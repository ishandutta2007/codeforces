#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int c,v0,v1,a,l;
  cin>>c>>v0>>v1>>a>>l;
  int ans=0,v=v0;
  c-=l;
  while(1){
    c+=l;
    ans++;
    if(c<=v) break;
    c-=v;
    v+=a;
    if(v>v1) v=v1;
  }
  cout<<ans<<endl;
  return 0;
}