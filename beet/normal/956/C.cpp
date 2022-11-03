#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  vector<Int> u(v);
  for(Int i=1;i<n;i++) chmax(u[i],u[i-1]);
  for(Int i=n-1;i>0;i--) chmax(u[i-1],u[i]-1);
  Int ans=0;
  for(Int i=0;i<n;i++) ans+=u[i]-v[i];
  cout<<ans<<endl;
  return 0;
}