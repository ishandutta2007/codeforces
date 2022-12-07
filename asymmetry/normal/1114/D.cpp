#include <bits/stdc++.h>

using namespace std;

int n, l;
int t[5011];
int dp[5011][5011];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
	}
	for(int i=1; i<=n; ++i)
	{
		if(t[i]!=t[i-1])
		{
			++l;
			t[l]=t[i];
		}
	}
	n=l;
	for(int i=1; i<n; ++i)
	{
		dp[i][i+1]=1;
	}
	for(int i=2; i<n; ++i)
	{
		for(int j=1; j+i<=n; ++j)
		{
			dp[j][j+i]=1000000000;
			if(t[j]==t[i+j])
			{
				dp[j][j+i]=dp[j+1][j+i-1]+1;
			}
			dp[j][j+i]=min(dp[j][j+i], dp[j][j+i-1]+1);
			dp[j][j+i]=min(dp[j][j+i], dp[j+1][j+i]+1);
		}
	}
	printf("%d", dp[1][n]);
	return 0;
}