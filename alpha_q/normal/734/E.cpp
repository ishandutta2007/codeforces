#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

bitset <N> vis;
int n, c[N], d[N], tot = 0, label[N];
vector <int> g[N], compressed[N];

void dfs (int u) {
	vis[u] = 1, label[u] = tot;
	for (int v : g[u]) 
		if (!vis[v] and c[v] == c[u]) dfs(v);
}

void bfs (int s) {
	queue <int> q;
	memset(d, -1, sizeof d);
	d[s] = 0, q.push(s);

	while (not q.empty()) {
		int u = q.front(); q.pop();
		for (int v : compressed[u]) if (d[v] == -1) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
}

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) ++tot, dfs(i);
	}

	for (int u = 1; u <= n; ++u)
		for (int v : g[u]) if (label[u] != label[v])
			compressed[label[u]].push_back(label[v]);

	bfs(1);
	int dist = -1, far = -1;
	for (int i = 1; i <= tot; ++i) {
		if (d[i] > dist) dist = d[i], far = i;
	}

	bfs(far); dist = -1;
	for (int i = 1; i <= tot; ++i) dist = max(dist, d[i]);

	printf("%d\n", dist + 1 >> 1);
	return 0;
}