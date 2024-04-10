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
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  vector<Int> sm(n+1,0);
  for(Int i=0;i<n;i++) sm[i+1]=sm[i]+a[i];  

  vector<Int> dp(n+1,0);
  for(Int i=0;i<n;i++){
    Int res=sm[i]-dp[i]*3;
    dp[i+1]=dp[i]+min(a[i]/2,(res+a[i])/3);
  }  
  
  cout<<dp[n]<<endl;
  return 0;
}