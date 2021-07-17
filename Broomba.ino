#include <AFMotor.h>
#include <SoftwareSerial.h>
#define BTTX 10 
#define BTRX 11
SoftwareSerial mySerial(BTTX, BTRX);
AF_DCMotor motor1(4);
AF_DCMotor motor2(3);
AF_DCMotor motor3(2, MOTOR12_64KHZ);
AF_DCMotor motor4(1);
char incomingByte = '*';

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
 
}

void loop()
{
  if (mySerial.available() > 0)
  {
    incomingByte = mySerial.read();
    Serial.println(incomingByte);
    Stop();
  }



  switch(incomingByte)
  {
    case 'S':
    Stop();
    Serial.println("Stop");
    break;
    
    case 'F':
    forward();
    Serial.println("Forward");
    break;

    case 'R':
    right();
    Serial.println("Right");
    break;

    case 'L':
    left();
    Serial.println("Left");
    break;

    case 'B':
    back();
    Serial.println("Back");
    break;

    case 'M':
    mop();
    Serial.println("mopper on");
    delay(1000);  
    break;
    

    case 'W':
    pump();
    Serial.println("Water pump");
    break;

    case 'X':
    mop_off();
    Serial.println("mopper off");
    break;
  }
}


void forward()
{
 motor2.setSpeed(255); //Define maximum velocity
 motor2.run(FORWARD); //rotate the motor clockwise
 motor1.setSpeed(255); //Define maximum velocity
 motor1.run(FORWARD); //rotate the motor clockwise
}
void back()
{
 motor2.setSpeed(255); 
 motor2.run(BACKWARD); //rotate the motor counterclockwise
 motor1.setSpeed(255); 
 motor1.run(BACKWARD); //rotate the motor counterclockwise
}
void left()
{
 motor2.setSpeed(255); //Define maximum velocity
 motor2.run(FORWARD); //rotate the motor clockwise
 motor1.setSpeed(0);
 motor1.run(RELEASE); //turn motor2 off
}
void right()
{
 motor2.setSpeed(0);
 motor2.run(RELEASE); //turn motor1 off
 motor1.setSpeed(255); //Define maximum velocity
 motor1.run(FORWARD); //rotate the motor clockwise
}

void mop() {
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  
}

void pump() {
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}
void mop_off() {
  motor3.setSpeed(0);
  motor3.run(RELEASE);
}
void Stop()
{
 motor2.setSpeed(0);
 motor2.run(RELEASE); //turn motor1 off
 motor1.setSpeed(0);
 motor1.run(RELEASE); //turn motor2 off
 motor4.setSpeed(0);
 motor4.run(RELEASE);
 
}
