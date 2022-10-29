#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3005;

#define ll long long
#define pii pair<int, int>

int n;
vector<int> G[N];
ll f[N][N];
vector<pii> D[N];
int sz[N][N], id[N][N], dis[N][N];

void dfs(int p, int fa, int *dis, int* sz) {
	sz[p] = 1;
	dis[p] = dis[fa] + 1;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p, dis, sz);
			sz[p] += sz[e];
		}
	}
}
void dfs(int p, int fa, int v, int *id) {
	id[p] = v;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p, v, id);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
		for (auto e : G[i]) {
			dfs(e, i, dis[i], sz[i]);
			dfs(e, i, sz[i][e], id[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i ^ j) {
				D[dis[i][j]].emplace_back(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = -1e18;
		}
	}
	for (auto e : D[1]) {
		int x = e.first, y = e.second;
		f[x][y] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (auto par : D[i]) {
			int x = par.first, y = par.second;
			if (f[x][y] < 0)
				continue;
			f[x][y] += (n - id[x][y]) * sz[x][y];
			for (auto e : G[x]) {
				if (dis[e][y] > i) {
					f[e][y] = max(f[e][y], f[x][y]);
				}
			}
			for (auto e : G[y]) {
				if (dis[x][e] > i) {
					f[x][e] = max(f[x][e], f[x][y]);
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, f[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}