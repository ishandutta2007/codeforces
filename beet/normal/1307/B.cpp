#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed solve(){
  Int n,x;
  cin>>n>>x;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  Int ans=1e18;
  for(Int a:as){
    if(a<=x){
      chmin(ans,(x+a-1)/a);
    }else{
      chmin(ans,2);
    }
  }
  cout<<ans<<"\n";
  return 0;
}

signed main(){
  Int t;
  cin>>t;
  while(t--) solve();
  cout<<flush;
  return 0;
}