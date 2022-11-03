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
  Int n,d;
  cin>>n>>d;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];
  for(Int i=1;i<n;i++){
    while(as[i]>0){
      if(d<i) break;
      as[i]-=1;
      as[0]+=1;
      d-=i;
    }
  }
  cout<<as[0]<<endl;
  return 0;
}

signed main(){
  Int t;
  cin>>t;
  while(t--) solve();
  return 0;
}