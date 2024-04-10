#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  char ch = 0;
  int result = 0;
  int x = 0 ;
  int y = 0;
  int kingdom = -1;
  for(int i = 0 ; i < n ;i++){
    cin>>ch;
    if(ch == 'R'){
      y++;
    } else
      x++;
    if(kingdom == -1){
      if(y < x){
        kingdom = 1;
      } else
        kingdom = 2;
    } else{
      if(kingdom == 1 && x < y){
        kingdom = 2;
        result++;
      }
      if(kingdom == 2 && y < x){
        kingdom = 1;
        result++;
      }
    }
  }
  cout<<result;
  return 0;
}