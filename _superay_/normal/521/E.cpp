#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, dfn[N], pa[N], dfc;
pair<int, int> lab[N];
vector<int> G[N];
void Gao(int u1, int v1, int u2, int v2) {
	puts("YES");
	int w = u2;
	while (lab[w] != make_pair(u1, v1)) {
		w = pa[w];
	}
	vector<int> a1, a2, a3;
	while (w != v1 && w != v2) {
		a1.push_back(w);
		w = pa[w];
	}
	a1.push_back(w);
	w = a1.back();
	while (w != v2) {
		a2.push_back(w);
		w = pa[w];
	}
	a2.push_back(w);
	w = u2;
	while (w != a1[0]) {
		a2.push_back(w);
		w = pa[w];
	}
	a2.push_back(w);
	reverse(a2.begin(), a2.end());
	w = a1.back();
	while (w != v1) {
		a3.push_back(w);
		w = pa[w];
	}
	a3.push_back(w);
	w = u1;
	while (w != a1[0]) {
		a3.push_back(w);
		w = pa[w];
	}
	a3.push_back(w);
	reverse(a3.begin(), a3.end());
	printf("%d", (int)a1.size()); for (int x : a1) printf(" %d", x); puts("");
	printf("%d", (int)a2.size()); for (int x : a2) printf(" %d", x); puts("");
	printf("%d", (int)a3.size()); for (int x : a3) printf(" %d", x); puts("");
	exit(0);
}
void dfs(int u, int lst) {
	pa[u] = lst;
	dfn[u] = ++dfc;
	for (int v : G[u]) {
		if (!dfn[v]) {
			dfs(v, u);
		} else if (dfn[v] < dfn[u] && v != lst) {
			int w = u;
			while (w != v) {
				if (lab[w].first) {
					Gao(lab[w].first, lab[w].second, u, v);
				}
				lab[w] = make_pair(u, v);
				w = pa[w];
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i, 0);
	puts("NO");
	return 0;
}