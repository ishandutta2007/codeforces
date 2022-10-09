#include <iostream>
#include <bitset>

using namespace std;
int const nmax = 1000000;
bitset <5 + nmax> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n ,m , k;
  cin>>n>>m>>k;
  int a;
  for(int i = 0 ; i < m ;i++){
    cin>>a;
    v[a] = 1;
  }
  a = 1;
  if(v[a] == 1){
    cout<<a;
    return 0;
  }
  int x,y;
  for(int i = 0 ; i < k ;i++){
    cin>>x>>y;
    if(x == a){
      a = y;
      if(v[a]){
        cout<<a;
        return 0;
      }
    } else if(y == a){
      a = x;
      if(v[a]){
        cout<<a;
        return 0;
      }
    }
  }
  cout<<a;
  return 0;
}