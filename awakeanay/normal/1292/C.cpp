#include <iostream>
#include <vector>

#define int long long
#define MAXN 3005

int n;
std::vector<int> Adj[MAXN];
int sec[MAXN][MAXN];
int count[MAXN][MAXN];
int dp[MAXN][MAXN];
int ans;

void dfs1(int x, int p, int u, int v) {
	sec[v][x] = u;
	count[u][v]++;
	for(int j : Adj[x]) {
		if(j != p)
			dfs1(j, x, u, v);
	}
}

int dfs2(int u, int v) {
	if(dp[u][v] != 0)
		return dp[u][v];
	int cur = count[v][sec[v][u]]*count[u][sec[u][v]];
	int add = 0;
	for(int i : Adj[u])
		if(i != sec[u][v])
			add = std::max(add, dfs2(i, v));
	for(int i : Adj[v])
		if(i != sec[v][u])
			add = std::max(add, dfs2(u, i));
	dp[u][v] = cur + add;
	ans = std::max(ans, dp[u][v]);
	return dp[u][v];
}

signed main() {
	std::cin >> n;
	
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j : Adj[i]) {
			dfs1(i, j, i, j);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j : Adj[i]) {
			dfs2(i, j);
		}
	}
	
	std::cout << ans << std::endl;
	
	return 0;
}