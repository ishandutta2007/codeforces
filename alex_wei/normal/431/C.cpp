#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,k,d,dp[102][102][2],ans; 
int main()
{
	cin>>n>>k>>d;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int l=max(i-1ll,j-k);l<j;l++)
				if(j-l>=d)dp[i][j][1]=(dp[i][j][1]+dp[i-1][l][0]+dp[i-1][l][1])%mod;
				else dp[i][j][1]=(dp[i][j][1]+dp[i-1][l][1])%mod,dp[i][j][0]=(dp[i][j][0]+dp[i-1][l][0])%mod;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[i][n][1])%mod;
	cout<<ans;
	return 0;
}