#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,d;
  string s;
  cin>>n>>d>>s;
  vector<Int> dp(n,-1);
  dp[0]=0;
  for(Int i=0;i<n;i++){
    if(dp[i]<0) continue;
    if(s[i]=='0') continue;
    for(Int j=1;j<=d&&i+j<n;j++){
      if(s[i+j]=='0') continue;
      if(dp[i+j]<0||dp[i+j]>dp[i]+1)
	dp[i+j]=dp[i]+1;
    }
  }
  cout<<dp[n-1]<<endl;
  return 0;
}