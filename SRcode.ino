/*Program to demonstrate the working of a 74HC595 Shift Register
with an arduino.

Authors:

Suryoday Basak
Sukrit Venkatagiri
Sampath Shanmugam

*/

int latch=10;
int clock=9;
int data=8;

//The latch pin, clock pin and data pin are connected to pins
//10, 9 and 8 of the arduino, respectively.

void setRegister()
{ 
  //This function initializes the 74HC595 IC
  digitalWrite(latch,LOW);
  digitalWrite(clock,LOW);
  digitalWrite(data,LOW);
}

void useRegister()
{  
  setRegister();
  //Makes the register ready.
  
  digitalWrite(data,HIGH);//Writes the first bit to the shift register
  digitalWrite(clock,HIGH);
  digitalWrite(latch,HIGH);
  
  for(int i=0;i<8;i++)
  {
  digitalWrite(data,LOW);
  digitalWrite(clock,HIGH);
  digitalWrite(latch,HIGH);

  setRegister();
  
  delay(500);
  //This loop shifts the bit, in intervals of 500ms.
  }
  
}

void setup()
{
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  
  void setRegister();
}

void loop()
{ 
  useRegister();
}
