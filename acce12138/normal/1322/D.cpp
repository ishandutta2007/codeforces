#include <bits/stdc++.h>

const int maxn = 4111;
const int inf = 0x3f3f3f3f;
int n, m, l[maxn], s[maxn], c[maxn];

int dp[maxn][maxn], mx[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", l+i);
	for(int i=1; i<=n; i++) scanf("%d", s+i);
	for(int i=1; i<=n+m; i++) scanf("%d", c+i);
	
	for(int i=0; i<maxn; i++) for(int j=0; j<maxn; j++) dp[i][j] = -inf;
	for(int i=1; i<=n+m; i++) dp[i][0] = 0;
	for(int i=n; i>=1; i--)
	{
		//choosing
		for(int k=mx[l[i]]; k>=0; k--) dp[l[i]][k+1] = std::max(dp[l[i]][k+1], dp[l[i]][k] - s[i] + c[l[i]]);
		mx[l[i]]++;
		//promoting
		for(int j=0; j<=n+m; j++) for(int k=mx[j]; k>=0; k--) if(dp[j][k] != -inf)
		{
			dp[j+1][k/2] = std::max(dp[j+1][k/2], dp[j][k] + c[j+1] * (k/2));
			mx[j+1] = std::max(mx[j+1], k/2);
		}
	}
	printf("%d\n", dp[n+m][0]);
	return 0;
}