#include <iostream>
#include <cmath>

using namespace std;
int const nmax = 10000;
int v[5 + nmax];
int main()
{
  int n ,m;
  cin>>n>>m;
  int k;
  bool ok = 0;
  bool ok2 = 0;
  int a;
  for(int i = 0 ; i < m ;i++){
    cin>>k;
    for(int j = 0 ; j <= nmax ;j++)
      v[j] = 0;
    ok = 0;
    for(int j = 0 ; j < k ;j++){
      cin>>a;
      if(v[int(fabs(a))] == 0){
        if(0 < a)
          v[int(fabs(a))] = 2;
        else
          v[int(fabs(a))] = 1;
      } else{
        if(0 < a && v[int(fabs(a))] == 1)
          ok = 1;
        else if(a < 0 && v[int(fabs(a))] == 2)
          ok = 1;
      }
    }
    if(ok == 0){
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
  return 0;
}