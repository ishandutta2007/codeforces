#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005][2];
int main()
{
	int n,m;
	string a,b;
	cin >> n >> m >> a >> b;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dp[i][j][1]=max(0,max(dp[i-1][j][1],dp[i][j-1][1])-1);
			if (a[i-1]==b[j-1])
			dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]+2);
			dp[i][j][0]=max(dp[i][j][1],max(dp[i-1][j][0],dp[i][j-1][0]));
		}
	}
	printf("%d",dp[n][m][0]);
}