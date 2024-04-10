#include <bits/stdc++.h>

using namespace std;

int n, gh, l, r, x, y;
int t[4001];
int dp[2011][2011];

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		for(int i=1; i<=n<<1; ++i)
		{
			scanf("%d", &t[n+n-i+1]);
		}
		for(int i=0; i<=n; ++i)
		{
			for(int j=0; j<=n; ++j)
			{
				dp[i][j]=0;
			}
		}
		dp[0][0]=1e9;
		for(int i=0; i<n<<1; ++i)
		{
			for(int j=0; j<=min(i, n); ++j)
			{
				l=j;
				r=i-j;
				if(!dp[l][r] || l>n || r>n)
				{
					continue;
				}
				x=t[i+1];
				if(!l)
				{
					y=1e9;
				}
				else
				{
					y=t[l+r];
				}
				if(x<y)
				{
					dp[r+1][l]=max(dp[r+1][l], y);
				}
				if(x<dp[l][r])
				{
					dp[l+1][r]=max(dp[l+1][r], dp[l][r]);
				}
			}
		}
		if(dp[n][n])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}