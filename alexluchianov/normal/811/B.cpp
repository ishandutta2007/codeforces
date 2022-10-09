#include <iostream>

using namespace std;
int const nmax = 10000;
int v[5 + nmax];

int main()
{
  int n ,m;
  cin>>n>>m;
  for(int i = 1 ; i <= n ;i++){
    cin>>v[i];
  }
  int l , r , x;
  int scount = 0;
  for(int i = 1 ;i <= m ;i++){
    cin>>l>>r>>x;
    scount = 0;
    for(int j = l ; j <= r ;j++){
      if(v[j] < v[x]){
        scount++;
      }
    }
    if(scount == x - l){
      cout<<"Yes\n";
    } else
      cout<<"No\n";
  }
  return 0;
}