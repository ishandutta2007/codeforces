#include <iostream>

using namespace std;

int main()
{
  int a ,b;
  cin>>a>>b;
  int s = 0;
  while(a <= b){
    a *= 3;
    b = (b<<1);
    s++;
  }
  cout<<s;
  return 0;
}