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
  Int n;
  cin>>n;
  string s;
  cin>>s;
  vector<Int> dp(n,0),pd(n,0);
  for(Int i=0;i<n;i++){
    if(i) dp[i]=dp[i-1];
    if(s[i]=='G') dp[i]++;
    else dp[i]=0;
  }
  for(Int i=n-1;i>=0;i--){
    if(i+1<n) pd[i]=pd[i+1];
    if(s[i]=='G') pd[i]++;
    else pd[i]=0;
  }
  
  Int ans=0,cnt=0;
  for(Int i=0;i<n;i++){
    chmax(ans,dp[i]);
    chmax(ans,pd[i]);
    cnt+=s[i]=='G';
  }
  
  for(Int i=0;i<n;i++)
    chmax(ans,(i-1>0?dp[i-1]:0)+1+(i+1<n?pd[i+1]:0)); 

  chmin(ans,cnt);
  cout<<ans<<endl;
  return 0;
}