#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int sum = 0;
  int l = 0, r = 0, u = 0, d = 0;
  char c;
  for(int i = 1 ; i <= n ;i++){
    cin>>c;
    if(c == 'L'){
      if(0 < r){
        l = 0;
        r = 0;
        u = 0;
        d = 0;
        sum++;
      }
      l++;
    } else if(c == 'R'){
      if(0 < l){
        l = 0;
        r = 0;
        u = 0;
        d = 0;
        sum++;
      }
      r++;
    } else if(c == 'U'){
      if(0 < d){
        l = 0;
        r = 0;
        u = 0;
        d = 0;
        sum++;
      }
      u++;
    } else if(c == 'D'){
      if(0 < u){
        l = 0;
        r = 0;
        u = 0;
        d = 0;
        sum++;
      }
      d++;
    }
  }
  cout<<sum + 1;
  return 0;
}