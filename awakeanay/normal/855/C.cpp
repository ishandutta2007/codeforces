#include <iostream>
#include <vector>

#define int long long
#define MOD 1000000007
#define MAXN 100005

int n, m;
int k, x;
int ans = 0;
std::vector<int> Adj[MAXN];
std::vector<int> dp[MAXN][3];

void dfs(int u, int p) {
	for(int j : Adj[u])
		if(j != p)
			dfs(j, u);

	for(int j = 0; j < 3; j++) {
		std::vector<int> cur(x+1, 0);
		cur[0] = (j == 0)*(k-1) + (j == 2)*(m-k);
		cur[1] = (j == 1);

		for(int v : Adj[u]) {
			if(v == p)
				continue;

			std::vector<int> next(x+1, 0);
			std::vector<int> vcur(x+1, 0);

			for(int l = 0; l <= x; l++)
				vcur[l] = (dp[v][0][l] + dp[v][2][l]*(j != 1) + (j == 0)*dp[v][1][l])%MOD;

			for(int l = 0; l <= x; l++)
				for(int h = 0; h+l <= x; h++)
					next[h+l] = (next[h+l] + cur[l]*vcur[h])%MOD;

			cur = next;
		}

		if(u == 0)
			for(int j : cur)
				ans = (ans + j)%MOD;

		dp[u][j] = cur;
	}
}

signed main() {
	std::cin >> n >> m;

	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}

	std::cin >> k >> x;

	dfs(0, -1);
	std::cout << ans << std::endl;

	return 0;
}