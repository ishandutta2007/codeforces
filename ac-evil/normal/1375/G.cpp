#include <bits/stdc++.h>
const int N = 200005;
struct Edge { int v, nxt; } e[N * 2];
int G[N], edges = 0;
void adde(int u, int v) {
	e[edges] = (Edge){v, G[u]}; G[u] = edges++;
}
int col[N];
void dfs(int u, int f) {
	for (int i = G[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == f) continue;
		col[v] = 1 - col[u];
		dfs(v, u);
	}
}
int n;
int main() {
	scanf("%d", &n);
	memset(G, -1, sizeof G);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	dfs(1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += col[i];
	printf("%d\n", std::min(cnt, n - cnt) - 1);
	return 0;
}