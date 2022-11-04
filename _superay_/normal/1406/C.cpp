#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, sz[N], mx[N];
vector<int> G[N];
void dfs(int u, int lst) {
	sz[u] = 1;
	mx[u] = 0;
	for (int v : G[u]) if (v != lst) {
		dfs(v, u);
		sz[u] += sz[v];
		mx[u] = max(mx[u], sz[v]);
	}
	mx[u] = max(mx[u], n - sz[u]);
}
int lf, fa;
void dfs2(int u, int lst) {
	int isl = 1;
	for (int v : G[u]) if (v != lst) {
		isl = 0;
		dfs2(v, u);
	}
	if (isl) lf = u, fa = lst;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) G[i].clear();
		int eex = 0, eey = 0;
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eex = u, eey = v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		int mn = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) mn = min(mn, mx[i]);
		vector<int> ve;
		for (int i = 1; i <= n; i++) {
			if (mx[i] == mn) {
				ve.push_back(i);
			}
		}
		if ((int)ve.size() == 1) {
			printf("%d %d\n%d %d\n", eex, eey, eex, eey);
			continue;
		}
		dfs2(ve[0], ve[1]);
		printf("%d %d\n%d %d\n", lf, fa, lf, ve[1]);
	}
	return 0;
}