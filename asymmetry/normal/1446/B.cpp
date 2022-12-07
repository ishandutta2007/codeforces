#include <bits/stdc++.h>

using namespace std;

int n, m, odp;
char s[5001];
char c[5001];
int dp[5001][5001];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	scanf("%s", c+1);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			dp[i][j]=max({dp[i][j], dp[i][j-1]-1, dp[i-1][j]-1, dp[i-1][j-1]-2+4*(s[i]==c[j])});
			odp=max(odp, dp[i][j]);
		}
	}
	printf("%d\n", odp);
	return 0;
}