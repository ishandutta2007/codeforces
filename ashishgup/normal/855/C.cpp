#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, k, x;
int dp[N][3][11];
vector<int> g[N];

void dfs(int u, int par)
{
	dp[u][0][0] = k - 1;
	dp[u][1][1] = 1;
	dp[u][2][0] = m - k;
	int ndp[3][11];
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u);
		memset(ndp, 0, sizeof(ndp));
		for(int j = 0; j <= x; j++)
		{
			for(int k = 0; j + k <= x; k++)
			{
				ndp[0][j + k] += dp[u][0][j] * (dp[it][0][k] + dp[it][1][k] + dp[it][2][k]);
				ndp[0][j + k] %= MOD;
				ndp[1][j + k] += dp[u][1][j] * dp[it][0][k];
				ndp[1][j + k] %= MOD;
				ndp[2][j + k] += dp[u][2][j] * (dp[it][0][k] + dp[it][2][k]);
				ndp[2][j + k] %= MOD;
			}
		}
		for(int i = 0; i < 3; i++)
			for(int j = 0; j <= x; j++)
				dp[u][i][j] = ndp[i][j];
 	}
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> k >> x;
	dfs(1, 1);
	int ans = 0;
	for(int i = 0; i <= x; i++)
		ans += dp[1][0][i] + dp[1][1][i] + dp[1][2][i];
	ans %= MOD;
	cout << ans;
	return 0;
}