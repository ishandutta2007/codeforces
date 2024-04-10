#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int mod = 998244353;
int n, a[N][N], fa[N], cv[N], ce[N], lst[N];
int tot, lab[N], f[N][N], tf[N], sz[N];
vector<int> G[N];
void dfs(int u) {
	if (!G[u].size()) {
		sz[u] = 1;
		f[u][1] = 1;
		return;
	}
	f[u][0] = 1;
	sz[u] = 0;
	for (int v : G[u]) {
		dfs(v);
		for (int i = 0; i <= sz[u] + sz[v]; i++) tf[i] = 0;
		for (int i = 0; i <= sz[u]; i++)
			for (int j = 0; j <= sz[v]; j++) {
				tf[i + j] = (tf[i + j] + 1ll * f[u][i] * f[v][j]) % mod;
			}
		sz[u] += sz[v];
		for (int i = 0; i <= sz[u]; i++) f[u][i] = tf[i];
	}
	f[u][1] = (f[u][1] + 1) % mod;
}
struct Edge {
	int u, v, w;
	inline bool operator < (const Edge &oth) const {
		return w < oth.w;
	}
};
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) {
		ce[x]++;
		return x;
	}
	fa[y] = x;
	cv[x] += cv[y];
	ce[x] += ce[y];
	ce[x]++;
	return x;
}
int main() {
	scanf("%d", &n);
	vector<Edge> ve;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			if (i < j) {
				ve.push_back((Edge){i, j, a[i][j]});
			}
		}
	}
	sort(ve.begin(), ve.end());
	for (int i = 1; i <= n; i++) fa[i] = i, cv[i] = 1, ce[i] = 0, lst[i] = i;
	tot = n;
	for (auto &e : ve) {
		int x = Union(e.u, e.v);
		if (ce[x] == cv[x] * (cv[x] - 1) / 2) {
			++tot;
			for (int i = 1; i <= n; i++) if (Find(i) == x) {
				if (lab[lst[i]] < tot) {
					lab[lst[i]] = tot;
					G[tot].push_back(lst[i]);
				}
				lst[i] = tot;
			}
		}
	}
	dfs(tot);
	for (int i = 1; i <= n; i++) printf("%d ", f[tot][i]);
	return 0;
}