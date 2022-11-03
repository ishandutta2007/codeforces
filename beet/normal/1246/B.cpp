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
const Int MAX = 2e5+100;
Int dp[MAX]={};

signed main(){
  for(Int i=2;i<MAX;i++)
    if(!dp[i]) for(Int j=i;j<MAX;j+=i) dp[j]=i;

  Int n,k;
  cin>>n>>k;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  using P = pair<Int, Int>;
  map<vector<P>, Int> mp;

  auto inv=
    [&](vector<P> vp){
      for(auto &p:vp)
        p.second=k-p.second;
      return vp;
    };

  Int ans=0;
  for(Int i=0;i<n;i++){
    map<Int, Int> cnt;
    Int a=as[i];
    while(a!=1){
      cnt[dp[a]]++;
      a/=dp[a];
    }

    vector<P> vp;
    for(auto p:cnt)
      if(p.second%k)
        vp.emplace_back(p.first,p.second%k);

    ans+=mp[inv(vp)];
    mp[vp]++;
  }

  cout<<ans<<endl;
  return 0;
}