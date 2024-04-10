#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
const int INF = 0x3f3f3f3f;
int n, m, a[N], must[N], lb[N], rb[N], dfn[N], low[N], dfc, stk[N], tp, instk[N], scc, bel[N], deg[N], que[N];
vector<int> idx[N], ps[N], G[N], T[N], R[N];
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
	for (int j = 0; j < m; j++) {
		scanf("%d", &a[j]);
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
			T[bel[u]].push_back(bel[v]);
		}
	}
	for (int u = 1; u <= scc; u++) {
		lb[u] = N, rb[u] = -1;
		sort(T[u].begin(), T[u].end());
		T[u].resize(unique(T[u].begin(), T[u].end()) - T[u].begin());
		for (int v : T[u]) deg[v]++, R[v].push_back(u);
	}
	for (int j = 0; j < m; j++) {
		int cc = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i][j] == '#') {
				cc++;
				if (cc == a[j]) {
					int u = bel[idx[i][j]];
					must[u] = 1;
					lb[u] = min(lb[u], j);
					rb[u] = max(rb[u], j);
				}
			}
		}
	}
	int ql = 1, qr = 0;
	for (int u = 1; u <= scc; u++) if (!deg[u]) que[++qr] = u;
	while (ql <= qr) {
		int u = que[ql++];
		int st = 0;
		for (int v : R[u]) st |= must[v];
		if (st && must[u]) {
			lb[u] = N, rb[u] = -1;
		}
		must[u] |= st;
		for (int v : T[u]) if (!--deg[v]) que[++qr] = v;
	}
	vector<pair<int, int> > vp;
	vector<int> va;
	for (int i = scc; i >= 1; i--) {
		int u = que[i];
		if (lb[u] <= rb[u]) {
			va.push_back(lb[u]);
			va.push_back(rb[u]);
			vp.emplace_back(lb[u], rb[u]);
			for (int v : R[u]) {
				lb[v] = min(lb[v], lb[u]);
				rb[v] = max(rb[v], rb[u]);
			}
		}
	}
	sort(vp.begin(), vp.end());
	sort(va.begin(), va.end());
	va.resize(unique(va.begin(), va.end()) - va.begin());
	int ans = 0, j = 0, cr = -1;
	for (int x : va) if (x > cr) {
		while (j < (int)vp.size() && vp[j].first <= x) {
			cr = max(cr, vp[j].second);
			j++;
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}