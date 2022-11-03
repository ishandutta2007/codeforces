#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,ans=0;
  cin>>n;
  vector<Int> dp(87,0);
  dp[0]=1;dp[1]=2;
  for(Int i=2;i<(Int)dp.size();i++){
    dp[i]=dp[i-1]+dp[i-2];
    //cout<<dp[i]<<endl;
  }
  //cout<<dp.back()<<endl;
  for(Int i=0;i<(Int)dp.size();i++) if(dp[i]<=n) ans=i;
  cout<<ans<<endl;
  return 0;
}