#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 1000000007;
int n;
vector<int> G[N];
int dp[N], sz[N], bot[N], dep[N], dfn[N], dfc, pos[N];
void dfs(int u, int lst) {
	pos[dfn[u] = ++dfc] = u;
	dep[u] = dep[lst] + 1;
	G[u].erase(find(G[u].begin(), G[u].end(), lst));
	sz[u] = 1;
	for (int v : G[u]) dfs(v, u), sz[u] += sz[v];
	if (G[u].size() == 1) bot[u] = bot[G[u][0]];
	else bot[u] = u;
	if (sz[u] & 1) { dp[u] = 0; return; }
	if (G[u].size() == 2) {
		int v1 = G[u][0], v2 = G[u][1];
		for (int tmp = 0; tmp < 2; tmp++) {
			int d1 = dep[bot[v1]] - dep[u], d2 = dep[bot[v2]] - dep[v2];
			if (d1 == d2) {
				if (!G[bot[v1]].size() && !G[bot[v2]].size()) dp[u] = (dp[u] + 1) % mod;
			} else if (d1 < d2) {
				if (!G[bot[v1]].size()) dp[u] = (dp[u] + dp[pos[dfn[v2] + d1 + 1]]) % mod;
			} else {
				if (!G[bot[v2]].size()) dp[u] = (dp[u] + dp[pos[dfn[v1] + d2]]) % mod;
			}
			swap(v1, v2);
		}
	} else {
		if (!G[bot[u]].size()) { dp[u] = sz[u] / 2; return; }
		if (G[G[u][0]].size() == 1) {
			dp[u] = dp[G[G[u][0]][0]];
		}
		for (int i = 0; i < 2; i++) {
			int v = G[bot[u]][i];
			if (!G[bot[v]].size() && dep[bot[v]] - dep[bot[u]] == dep[bot[u]] - dep[u] - 1) dp[u] = (dp[u] + dp[G[bot[u]][i ^ 1]]) % mod;
			if (G[v].size() == 1) {
				if (!G[bot[v]].size() && dep[bot[v]] - dep[bot[u]] - 1 == dep[bot[u]] - dep[u]) dp[u] = (dp[u] + dp[G[bot[u]][i ^ 1]]) % mod;
			} else if (G[v].size() == 2) {
				for (int j = 0; j < 2; j++) {
					int w = G[v][j];
					if (!G[bot[w]].size() && dep[bot[w]] - dep[bot[u]] - 1 == dep[bot[u]] - dep[u]) {
						int c1 = G[bot[u]][i ^ 1], c2 = G[v][j ^ 1];
						int d1 = dep[bot[c1]] - dep[c1], d2 = dep[bot[c2]] - dep[c2];
						if (d1 == d2) {
							if (!G[bot[c1]].size() && !G[bot[c2]].size()) dp[u] = (dp[u] + 1) % mod;
						} else if (d1 < d2) {
							if (!G[bot[c1]].size()) dp[u] = (dp[u] + dp[pos[dfn[c2] + d1 + 1]]) % mod;
						} else {
							if (!G[bot[c2]].size()) dp[u] = (dp[u] + dp[pos[dfn[c1] + d2 + 1]]) % mod;
						}
					}
				}
			}
		}
	}
}
inline int Gao(int u, int v) {
	int d1 = dep[bot[u]] - dep[u], d2 = dep[bot[v]] - dep[v];
	if (d1 == d2) {
		if (!G[bot[u]].size() && !G[bot[v]].size()) return 1;
	} else if (d1 < d2) {
		if (!G[bot[u]].size()) return dp[pos[dfn[v] + d1 + 1]];
	} else {
		if (!G[bot[v]].size()) return dp[pos[dfn[u] + d2 + 1]];
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < 2 * n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int rt = 1;
	for (int i = 2; i <= 2 * n; i++) {
		if (G[rt].size() < G[i].size()) {
			rt = i;
		}
	}
	if (G[rt].size() > 3) {
		puts("0");
		return 0;
	}
	if (G[rt].size() < 3) {
		int ans = (n > 1) ? ((2ll * n * n - 2 * n + 4) % mod) : 2;
		printf("%d\n", ans);
		return 0;
	}
	for (int u : G[rt]) dfs(u, rt);
	sort(G[rt].begin(), G[rt].end());
	int ans = 0;
	do {
		if (!G[G[rt][1]].size()) {
			ans = (ans + 1ll * dp[G[rt][0]] * dp[G[rt][2]]) % mod;
		} else if (G[G[rt][1]].size() == 2) {
			ans = (ans + 1ll * Gao(G[G[rt][1]][0], G[rt][0]) * Gao(G[G[rt][1]][1], G[rt][2])) % mod;
			ans = (ans + 1ll * Gao(G[G[rt][1]][1], G[rt][0]) * Gao(G[G[rt][1]][0], G[rt][2])) % mod;
		} else {
			ans = (ans + 1ll * Gao(G[G[rt][1]][0], G[rt][0]) * dp[G[rt][2]]) % mod;
			ans = (ans + 1ll * dp[G[rt][0]] * Gao(G[G[rt][1]][0], G[rt][2])) % mod;
		}
	} while (next_permutation(G[rt].begin(), G[rt].end()));
	ans = ans * 2 % mod;
	printf("%d\n", ans);
	return 0;
}