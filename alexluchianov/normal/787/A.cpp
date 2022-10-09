#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int a ,b;
  int c ,d;
  cin>>b>>a;
  cin>>d>>c;
  bool ok = 1;
  while(a < 10000000){
    if(a < c){
      a += b;
    } else if(a != c){
      c += d;
    } else{
      ok = 0;
      cout<<a;
      break;
    }
  }
  if(ok == 1)
    cout<<"-1";
  return 0;
}