#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n;
  cin>>n;
  int x[n];
  for(int i=0;i<n;i++) cin>>x[i];
  int dp[55];
  memset(dp,-1,sizeof(dp));
  int sum[n+1];
  sum[n]=0;
  for(int i=n-1;i>=0;i--) sum[i]=sum[i+1]+x[i];
  function<int(int)> dfs=[&](int v){
    if(v==n) return 0;
    if(~dp[v]) return dp[v];
    return dp[v]=max(x[v]+(sum[v+1]-dfs(v+1)),dfs(v+1));
  };
  int k=dfs(0);
  cout<<sum[0]-k<<" "<<k<<endl;
  return 0;
}