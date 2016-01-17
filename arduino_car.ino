#include <AFMotor.h> //import your motor shield library
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // begin serial communitication  
  Serial.println("Let's goooooo!");
  pinMode(trigPin, OUTPUT);// Output (pin 12) (Send sound waves)
  pinMode(echoPin, INPUT);// Input (pin 13) (recieve sound waves)
  motor1.setSpeed(175); //set the speed of the motors, between 0-255
motor2.setSpeed (175);  
}
 
void loop() {

   long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(3); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(8); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 45)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
  Serial.println ("Detected a close obstacle!" );
Serial.print ("Distance From Robot is " );
Serial.print ( distance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println ("The obstacle is a threat. Preparing to turn!!");
Serial.println (" Turning !");
    motor1.run(BACKWARD); 
    motor2.run (FORWARD); 

}
  else {
   Serial.println ("YAY! The path is clear! Going forward!");
   delay (3);
   motor1.run(BACKWARD);  //PS: I have my car set up backward, so my backward = forward. change as needed 
    motor2.run(BACKWARD);  
  }  
  
  

  
  
  
 
}
