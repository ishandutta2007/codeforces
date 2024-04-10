#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int k;
  cin>>k;
  int x=0,y;
  while(k--){
    cin>>y;
    x=max(x,y);
  }
  cout<<max(0LL,x-25)<<endl;
  return 0;
}