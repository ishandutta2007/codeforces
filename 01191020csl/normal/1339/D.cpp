#include<bits/stdc++.h>
using namespace std;
int deg[100001];
int head[100001], ver[200001], nxt[200001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
	++deg[u], ++deg[v];
}
int fa[100001], tmp[100001], cnt[100001];
void dfs(int x) {
	if (deg[x] == 1) return;
	int tmp0 = -1;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dfs(ver[i]);
			if (deg[ver[i]] == 1) ++cnt[x];
			if (tmp[ver[i]] == -1 || tmp0 + tmp[ver[i]] == 1 || tmp0 == -2) tmp0 = -2;
			else tmp0 = tmp[ver[i]];
		}
	if (tmp0 >= 0) tmp[x] = tmp0 ^ 1;
	else tmp[x] = -1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	int rt = 1;
	while (deg[rt] == 1) ++rt;
	dfs(rt);
	if (tmp[rt] >= 0) cout << 1;
	else cout << 3;
	int ans = n - 1;
	for (int i = 1; i <= n; i++)
		if (cnt[i]) ans -= cnt[i] - 1;
	cout << ' ' << ans << endl;
}