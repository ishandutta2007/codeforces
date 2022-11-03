#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i,j,k;
  int inf=1005;
  int ans=inf;
  int a[1005]={};
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  int dp[5][1005];
  fill(dp[0],dp[4],inf);
  dp[0][0]=0;
  for(i=0;i<n;i++){
    for(j=0;j<4;j++){
      if(dp[j][i]==inf) continue;
      dp[0][i+1]=min(dp[0][i+1],dp[j][i]+1);
      if((a[i]==1||a[i]==3)&&j!=1) dp[1][i+1]=min(dp[1][i+1],dp[j][i]);
      if((a[i]==2||a[i]==3)&&j!=2) dp[2][i+1]=min(dp[2][i+1],dp[j][i]);
    }
  }
  for(j=0;j<4;j++) ans=min(ans,dp[j][n]);
  cout << ans << endl;
  return 0;
}