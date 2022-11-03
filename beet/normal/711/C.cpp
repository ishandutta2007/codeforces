#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[110][110][110];
int main(){
  ll n,m,k,i,j,a,b;
  cin>>n>>m>>k;
  ll c[n];
  for(i=0;i<n;i++) cin>>c[i];
  ll p[n][m];
  for(i=0;i<n;i++)
    for(j=0;j<m;j++) cin>>p[i][j];
  memset(dp,-1,sizeof(dp));
  dp[0][0][0]=0;
  for(i=0;i<n;i++){
    for(j=0;j<=m;j++){
      for(a=0;a<n;a++){
	if(!~dp[i][j][a]) continue;
	if(c[i]){
	  if(c[i]==j)
	    if(~dp[i+1][c[i]][a]) dp[i+1][c[i]][a]=min(dp[i+1][c[i]][a],dp[i][j][a]);
	    else dp[i+1][c[i]][a]=dp[i][j][a];
	  else
	    if(~dp[i+1][c[i]][a+1]) dp[i+1][c[i]][a+1]=min(dp[i+1][c[i]][a+1],dp[i][j][a]);
	    else dp[i+1][c[i]][a+1]=dp[i][j][a];
	}else{
	  for(b=1;b<=m;b++){
	    if(b==j)
	      if(~dp[i+1][b][a]) dp[i+1][b][a]=min(dp[i+1][b][a],dp[i][j][a]+p[i][b-1]);
	      else dp[i+1][b][a]=dp[i][j][a]+p[i][b-1];
	    else
	      if(~dp[i+1][b][a+1]) dp[i+1][b][a+1]=min(dp[i+1][b][a+1],dp[i][j][a]+p[i][b-1]);
	      else dp[i+1][b][a+1]=dp[i][j][a]+p[i][b-1];
	  }
	}
      }
    }
  }
  /*
  for(i=0;i<n;i++){
    for(j=0;j<=m;j++){
      for(a=0;a<n;a++){
	if(!~dp[i][j][a]) continue;
	cout << i << ":"<<j<<":"<<a<<"/"<<dp[i][j][a]<<endl;
      }
    }
  }
  //*/
  ll ans=-1;
  for(i=1;i<=m;i++){
    if(!~dp[n][i][k]) continue;
    if(~ans) ans=min(ans,dp[n][i][k]);
    else ans=dp[n][i][k];
  }
  cout << ans << endl;
  return 0;
}