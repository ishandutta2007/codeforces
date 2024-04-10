#include <iostream>

using namespace std;
int cmmdc(int x , int y){
  if(y == 0)
    return x;
  else
    return cmmdc(y , x % y);
}
int main()
{
  int a , b , c;
  cin>>a>>b>>c;
  int x = a / cmmdc(a , b) , y = b / cmmdc(a , b);
  int dec = 0 , pow2 = 0, pow5 = 0;
  while(y % 2 == 0){
    pow2++;
    y /= 2;
  }
  while(y % 5 == 0){
    pow5++;
    y /= 5;
  }
  y = b / cmmdc(a , b);
  dec = max(pow2 , pow5);
  int curpos = 1;
  for(int i = 0 ; i < dec ;i++){
    x *= 10;
    if(c == x / y){
      cout<<curpos;
      return 0;
    }
    x %= y;
    curpos++;
  }
  int x2 = x;
  do{
    x *= 10;
    if(c == x / y){
      cout<<curpos;
      return 0;
    }
    x %= y;
    curpos++;
  }while(x != x2);

  cout<<-1;
  return 0;
}