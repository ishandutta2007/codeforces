#include <bits/stdc++.h>
using std::vector; using std::min;
typedef long long LL;
const int N = 200005;
struct Edge { int v, w, nxt; } e[N];
int G[N], edges = 0;
void adde(int u, int v, int w) {
	e[edges] = {v, w, G[u]}; G[u] = edges++;
}
int n, m, Q;
int low[N], dfn[N], st[N], top = 0, scc[N], no = 0, dfs_clock = 0;
void dfs(int u) {
	low[u] = dfn[u] = ++dfs_clock; st[++top] = u;
	for (int i = G[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (!dfn[v])
			dfs(v), low[u] = min(low[u], low[v]);
		else if (!scc[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		no++;
		for (;;) {
			int x = st[top--];
			scc[x] = no;
			if (x == u) break;
		}
	}
}
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
int vis[N]; LL val[N], w[N];
void find(int u, int id) {
	vis[u] = 1;
	for (int i = G[u]; ~i; i = e[i].nxt) {
		int v = e[i].v;
		if (scc[v] != id) continue;
		if (!vis[v]) {
			w[v] = w[u] + e[i].w;
			find(v, id);
		} else {
			LL tmp = w[u] + e[i].w - w[v];
			val[id] = val[id] ? gcd(val[id], tmp) : tmp;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	memset(G, -1, sizeof G);
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs_clock = 0, dfs(i);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) w[i] = 0, find(i, scc[i]);
	scanf("%d", &Q);
	while (Q--) {
		int v, s, t; scanf("%d%d%d", &v, &s, &t);
		if (!s) { puts("YES"); continue; }
		if (!val[scc[v]]) { puts("NO"); continue; }
		if ((t - s) % gcd(t, val[scc[v]]) == 0) puts("YES"); else puts("NO");
	}
	return 0;
}