#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
inline int Query(int u, int v) {
	printf("? %d %d\n", u, v);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}
int n, m, dfn[N], low[N], dfc, stk[N], tp, instk[N], scc, bel[N], deg[N];
vector<int> G[N], nG[N], buck[N];
void dfs(int u) {
	dfn[u] = low[u] = ++dfc;
	stk[++tp] = u;
	instk[u] = 1;
	for (int v : G[u]) {
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		++scc;
		int w;
		do {
			w = stk[tp--];
			instk[w] = 0;
			bel[w] = scc;
		} while (w != u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);
	for (int u = 1; u <= n; u++) {
		buck[bel[u]].push_back(u);
		for (int v : G[u]) if (bel[u] != bel[v]) {
			nG[bel[u]].push_back(bel[v]);
			deg[bel[v]]++;
		}
	}
	vector<int> stk;
	for (int i = 1; i <= scc; i++) if (!deg[i]) stk.push_back(i);
	while (stk.size() > 1) {
		int x = stk.back(); stk.pop_back();
		int y = stk.back(); stk.pop_back();
		while (buck[y].size()) {
			if (!Query(buck[x].back(), buck[y].back())) {
				swap(x, y);
			}
			buck[y].pop_back();
		}
		for (int v : nG[y]) {
			deg[v]--;
			if (!deg[v]) stk.push_back(v);
		}
		stk.push_back(x);
	}
	printf("! %d\n", buck[stk.back()].back());
	return 0;
}