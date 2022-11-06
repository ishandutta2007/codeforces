#include <bits/stdc++.h>
using std::max;
const int N = 5005, P = 998244353;
struct Edge { int v, nxt; } e[N * 2];
int G[N], edges = 0;
void adde(int u, int v) {
	e[edges++] = (Edge){v, G[u]}; G[u] = edges - 1;
}
int n, k, siz[N], f[N][N], g[N];
void dfs(int u, int fa) {
	f[u][1] = 1; siz[u] = 1;
	for (int i = G[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs(v, u);
		memset(g, 0, sizeof g);
		for (int i = 1; i <= siz[u]; i++)
			for (int j = 1; j <= siz[v]; j++) {
				// 1 : cut
				g[i] = (g[i] + 1LL * f[u][i] * f[v][j]) % P;
				// 2 : not cut
				if (i + j <= k) g[max(i, j + 1)] = (g[max(i, j + 1)] + 1LL * f[u][i] * f[v][j]) % P;
			}
		memcpy(f[u], g, sizeof g);
		siz[u] += siz[v];
	}
}
int main() {
	scanf("%d%d", &n, &k); k++;
	memset(G, -1, sizeof G);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= k; i++) ans = (ans + f[1][i]) % P;
	printf("%d", ans);
	return 0;
}