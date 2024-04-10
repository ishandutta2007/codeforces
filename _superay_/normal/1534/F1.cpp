#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int n, m, dfn[N], low[N], dfc, stk[N], tp, instk[N], scc, bel[N], deg[N];
vector<int> idx[N], ps[N], G[N];
string s[N];
char tmps[N];
inline void add_edge(int u, int v) {
	G[u].push_back(v);
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++dfc;
	stk[++tp] = u;
	instk[u] = 1;
	for (int v : G[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		int w;
		++scc;
		do {
			w = stk[tp--];
			instk[w] = 0;
			bel[w] = scc;
		} while (w != u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", tmps);
		s[i] = tmps;
		idx[i].resize(m);
		ps[i].resize(m);
	}
	ps[n].resize(m);
	int tot = 0;
	for (int j = 0; j < m; j++) {
		ps[n][j] = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i][j] == '#') {
				ps[i][j] = idx[i][j] = ++tot;
				if (ps[i + 1][j]) add_edge(ps[i][j], ps[i + 1][j]);
			} else {
				ps[i][j] = ps[i + 1][j];
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (s[i][j] == '#') {
				if (j > 0 && ps[i][j - 1]) add_edge(idx[i][j], ps[i][j - 1]);
				if (j < m - 1 && ps[i][j + 1]) add_edge(idx[i][j], ps[i][j + 1]);
				if (i > 0 && s[i - 1][j] == '#') add_edge(idx[i][j], idx[i - 1][j]);
			}
		}
	}
	for (int i = 1; i <= tot; i++) if (!dfn[i]) {
		Tarjan(i);
	}
	for (int u = 1; u <= tot; u++) {
		for (int v : G[u]) if (bel[v] != bel[u]) {
			deg[bel[v]]++;
		}
	}
	int ans = 0;
	for (int u = 1; u <= scc; u++) if (!deg[u]) ans++;
	printf("%d\n", ans);
	return 0;
}