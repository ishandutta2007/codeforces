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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n,k,x;
  cin>>n>>k>>x;
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i];

  Int po=1;
  for(Int j=0;j<k;j++) po*=x;

  vector<Int> dp(n+1,0),pd(n+1,0);
  for(Int i=0;i<n;i++)
    dp[i+1]=dp[i]|as[i];
  for(Int i=n-1;i>0;i--)
    pd[i-1]=pd[i]|as[i];

  Int ans=0;
  for(Int i=0;i<n;i++)
    chmax(ans,dp[i]|pd[i]|(as[i]*po));
  cout<<ans<<endl;
  return 0;
}