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
signed main(){
  Int n,c;
  cin>>n>>c;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  const Int MAX = 5e5+100;
  vector<Int> dp(MAX,0),cnt(MAX,0); 

  Int ans=0;
  for(Int i=0;i<n;i++){
    cnt[a[i]]++;
    if(a[i]==c) continue;
    Int res=cnt[a[i]]-cnt[c];
    chmax(ans,1);
    chmax(ans,res-dp[a[i]]);
    chmin(dp[a[i]],res-1);
  }
  
  ans+=cnt[c];
  cout<<ans<<endl;
  return 0;
}