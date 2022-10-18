#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

int num[2005],dp[3][2005][2005],dp2[3][2005][2005],two[2005];

int main()
{jizz
	int n,i,j,ans=0;
	cin >> n >> num[0];
	for(i=1;i<n;i++)
		cin >> num[i];
	for(i=0;i<n;i++)
	{
		if(num[i]==1) dp[1][i][i]=1;
		else dp[2][i][i]=1;
		for(j=i+1;j<n;j++)
		{
			dp[1][i][j]=dp[1][i][j-1];
			dp[2][i][j]=max(dp[2][i][j-1],dp[1][i][j-1]);
			if(num[j]==1) dp[1][i][j]++;
			else dp[2][i][j]++;
			dp[2][i][j]=max(dp[2][i][j],dp[1][i][j]);
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(num[i]==1) dp2[1][i][i]=1;
		else dp2[2][i][i]=1;
		for(j=i-1;j>=0;j--)
		{
			dp2[1][i][j]=dp2[1][i][j+1];
			dp2[2][i][j]=max(dp2[2][i][j+1],dp2[1][i][j+1]);
			if(num[j]==1) dp2[1][i][j]++;
			else dp2[2][i][j]++;
			dp2[2][i][j]=max(dp2[2][i][j],dp2[1][i][j]);
		}
		two[i]=two[i+1];
		if(num[i]==2) two[i]++;
	}
	ans=dp[2][0][n-1];
	for(i=0;i<n;i++)
		ans=max(ans,dp2[2][i][0]+two[i+1]);
	for(i=0;i<n;i++)
	{
		ans=max(ans,two[i+1]+dp[2][0][i]);
		for(j=i+1;j<n;j++)
			ans=max(ans,dp[1][0][i]+dp2[2][j][i+1]+two[j+1]);
	}
	cout << ans << "\n";
}