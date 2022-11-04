#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int INF = 0x3f3f3f3f;
int n, m, dist[N][2], ans[N], vis[N], d[N];
vector<pair<int, int> > rG[N], G[N];
queue<int> que;
int main() {
	scanf("%d%d", &n, &m);
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= m; i++) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		G[u].emplace_back(v, t);
		rG[v].emplace_back(u, t);
	}
	dist[n][0] = dist[n][1] = 0;
	ans[n] = 0;
	que.push(n);
	vis[n] = 1;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto &e : rG[u]) {
			int v = e.first, t = e.second;
			if (vis[v]) continue;
			dist[v][t] = min(dist[v][t], dist[u][ans[u]] + 1);
		}
		for (auto &e : rG[u]) {
			int v = e.first;
			if (vis[v]) continue;
			if (max(dist[v][0], dist[v][1]) < INF) {
				ans[v] = (dist[v][1] > dist[v][0]);
				que.push(v);
				vis[v] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (max(dist[i][0], dist[i][1]) == INF) ans[i] = (dist[i][1] == INF);
	}
	if (dist[1][ans[1]] == INF) printf("-1\n");
	else printf("%d\n", dist[1][ans[1]]);
	for (int i = 1; i <= n; i++) {
		printf("%d", ans[i]);
	}
	puts("");
	/*
	memset(d, 0x3f, sizeof(d));
	que.push(1);
	d[1] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto &e : G[u]) if (e.second == ans[u]) {
			int v = e.first;
			if (d[v] == 0x3f3f3f3f) {
				d[v] = d[u] + 1;
				que.push(v);
			}
		}
	}
	if (d[n] != dist[1][ans[1]]) assert(false);
	*/
	return 0;
}