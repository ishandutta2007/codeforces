#include <iostream>

using namespace std;

int v[10];
int v2[10];
int main()
{
  int n;
  cin>>n;
  int a;
  for(int i = 0 ; i < n ;i++){
    cin>>a;
    v[a]++;
  }
  for(int i = 0 ; i < n ;i++){
    cin>>a;
    v2[a]++;
  }
  int s = 0,s2 = 0;
  bool ok = 1;
  for(int i = 1 ; i <= 5 ;i++){
    if(v[i] < v2[i]){
      if((v2[i] - v[i]) % 2 == 0){
        s += (v2[i] - v[i]) / 2;
      } else{
        ok = 0;
        break;
      }
    } else{
      if((v[i] - v2[i]) % 2 == 0){
        s2 += (v[i] - v2[i]) / 2;
      } else{
        ok = 0;
        break;
      }
    }
  }
  if(s == s2 && ok == 1)
    cout<<s;
  else
    cout<<"-1";
  return 0;
}