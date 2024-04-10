#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int a ,b;
  cin>>a>>b;
  int step = 1;
  while(true){
    if((step & 1) == 1){
      if(step <= a){
        a -= step;
      } else{
        cout<<"Vladik";
        break;
      }
    } else{
      if(step <= b){
        b -= step;
      } else{
        cout<<"Valera";
        break;
      }
    }
    step++;
  }
  return 0;
}