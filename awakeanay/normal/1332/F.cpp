#include <iostream>
#include <vector>

#define int long long
#define MOD 998244353
#define MAX 400000

std::vector<int> g[MAX];
int dp[MAX][3];

void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = dp[u][2] = 1;
  int prod = 1;

	for(int j : g[u]) {
		if(j == p)
			continue;
		
		dfs(j, u);

    dp[u][0] *= (2*dp[j][0] + dp[j][1] + dp[j][2]);
    dp[u][1] *= (2*dp[j][0] + dp[j][2]);
    prod *= (dp[j][0] + dp[j][2]);

    dp[u][0] %= MOD;
    dp[u][1] %= MOD;
    prod %= MOD;
	}

  dp[u][2] = (dp[u][1] + MOD - prod)%MOD;
}

signed main() {
	int n;
	std::cin >> n;

	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

  dfs(0, -1);
  std::cout << (dp[0][0] + dp[0][2] + MOD - 1)%MOD << std::endl;

	return 0;
}