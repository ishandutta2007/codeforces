#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
vector <vector <int>> adj, rev;
int dpDown[MAXN], dpUp[MAXN];
int bio[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	rev.resize(N + 1);
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
}

void dfs_cycle(int x) {
	if (bio[x] == 2)
		return;
	bio[x] = 1;
	for (auto it : adj[x])
		if (bio[it] == 1) {
			puts("-1");
			exit(0);
		}
		else
			dfs_cycle(it);
	bio[x] = 2;
}

int calc_dp(int x, int *dp, vector <vector <int>> &graph) {
	if (dp[x])
		return dp[x];
	dp[x] = x;
	for (auto it : graph[x])
		dp[x] = min(dp[x], calc_dp(it, dp, graph));
	return dp[x];
}

void solve() {
	for (int i = 1; i <= N; i++)
		dfs_cycle(i);
	
	int uni = 0;
	string quant = "";
	for (int i = 1; i <= N; i++)
		if (calc_dp(i, dpDown, adj) == i && calc_dp(i, dpUp, rev) == i) {
			quant += 'A';
			uni++;
		}
		else
			quant += 'E';
			
	printf("%d\n%s\n", uni, quant.c_str());
}

int main() {
	load();
	solve();
	return 0;
}