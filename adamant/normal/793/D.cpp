#include <bits/stdc++.h>

using namespace std;

const int maxn = 81;
int dp[maxn][maxn][maxn][maxn];
int g[maxn][maxn];

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	memset(g, 0x3F, sizeof(g));
	memset(dp, 0x3F, sizeof(dp));
	int ans = g[0][0], t = g[0][0];
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		g[u][v] = min(g[u][v], c);
	}
	for(int i = 0; i < n; i++)
		dp[0][0][n - 1][i] = 0;
	for(int z = 0; z < k; z++)
		for(int l = 0; l < n; l++)
			for(int r = l; r < n; r++)
				for(int u = l; u <= r; u++)
					for(int v = l; v <= r; v++)
						dp[z + 1][v < u ? l : u + 1][v > u ? r : u - 1][v] = min(dp[z + 1][v < u ? l : u + 1][v > u ? r : u - 1][v], g[u][v] + dp[z][l][r][u]);
	for(int l = 0; l < n; l++)
		for(int r = 0; r < n; r++)
			for(int u = 0; u < n; u++)
				ans = min(ans, dp[k - 1][l][r][u]);
	if(ans == t)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}