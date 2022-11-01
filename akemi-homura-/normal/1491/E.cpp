#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int f[35];
int isf[N];
int n, sz[N];
vector<pair<int, int> > G[N];
bool ban[N];
pair<int, pair<int, int> > fnd;
void dfs(int u, int lst, int lstid, int tar1, int tar2) {
	sz[u] = 1;
	for (auto &e : G[u]) {
		if (ban[e.second]) continue;
		int v = e.first;
		if (v == lst) continue;
		dfs(v, u, e.second, tar1, tar2);
		sz[u] += sz[v];
	}
	if (sz[u] == tar1) {
		fnd.first = lstid;
		fnd.second.first = u;
		fnd.second.second = lst;
	} else if (sz[u] == tar2) {
		fnd.first = lstid;
		fnd.second.first = lst;
		fnd.second.second = u;
	}
}
bool gao(int rt, int id) {
	if (id <= 1) return true;
	fnd.first = 0;
	dfs(rt, 0, 0, f[id - 1], f[id - 2]);
	if (!fnd.first) return false;
	ban[fnd.first] = 1;
	int x = fnd.second.first, y = fnd.second.second;
	return gao(x, id - 1) && gao(y, id - 2);
}
int main() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= 30; i++) f[i] = f[i - 1] + f[i - 2];
	for (int i = 1; i <= 30; i++) if (f[i] < N) isf[f[i]] = i;
	scanf("%d", &n);
	if (!isf[n]) { puts("NO"); return 0; }
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
	}
	puts(gao(1, isf[n]) ? "YES" : "NO");
	return 0;
}