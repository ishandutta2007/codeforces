#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, dfn[N], low[N], stk[N], tp, dfc, instk[N], scc, bel[N];
long long dep[N], gw[N];
vector<pair<int, int> > G[N];
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfc;
	stk[++tp] = u;
	instk[u] = 1;
	for (auto &e : G[u]) {
		int v = e.first;
		if (!dfn[v]) {
			dep[v] = dep[u] + e.second;
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		int w;
		++scc;
		vector<int> cur;
		do {
			w = stk[tp--];
			instk[w] = 0;
			bel[w] = scc;
			cur.push_back(w);
		} while (w != u);
		for (int v : cur) {
			for (auto &e : G[v]) if (bel[e.first] == scc) {
				gw[scc] = __gcd(gw[scc], abs(dep[v] - dep[e.first] + e.second));
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	int q;
	scanf("%d", &q);
	while (q--) {
		int u, s, t;
		scanf("%d%d%d", &u, &s, &t);
		u = bel[u];
		if ((t - s) % __gcd(gw[u], 1ll * t) == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}