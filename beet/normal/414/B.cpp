#include<bits/stdc++.h>
using namespace std;
#define int long long
int MOD=1000000007LL;
int dp[2222][2222];
signed main(){
  memset(dp,0,sizeof(dp));
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++) dp[0][i]=1;
  for(int i=1;i<k;i++){
    for(int j=1;j<=n;j++){
      for(int l=j;l<=n;l+=j){
	(dp[i][j]+=dp[i-1][l])%=MOD;
      }
    }
  }
  int ans=0;
  for(int j=1;j<=n;j++) (ans+=dp[k-1][j])%=MOD;
  cout<<ans<<endl;
  return 0;
}