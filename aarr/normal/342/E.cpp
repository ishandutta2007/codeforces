#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100 * 1000 + 5, SQ = 217, LG = 17;
int n, t;

vector <int> adj[N];
int h[N];
int par[N][LG + 3];
bool c[N];
bool mark[N];
int dis[N];
queue<int> q;
vector <int> qs;
void dfs(int v) {
	for (auto u : adj[v]) {
		if (u != par[v][0]) {
			h[u] = h[v] + 1;
			par[u][0] = v;
			dfs(u);
		}
	}
}
void bfs() {
	for (int i = 1; i <= n; i++) {
		dis[i] = N;
		mark[i] = false;
		if (c[i]) {
			mark[i] = true;
			dis[i] = 0;
			q.push(i);
		}
	}
	while (q.size()) {
		int v = q.front();
		q.pop();
		for (auto u : adj[v]) {
			if (!mark[u]) {
				dis[u] = dis[v] + 1;
				mark[u] = true;
				q.push(u);
			}
		}
	}
}
int lca(int u, int v) {
	if (h[u] > h[v])
		swap(u, v);
	for (int i = LG; i >= 0; i--) {
		if (h[v] - (1 << i) >= h[u]) {
			v = par[v][i];
		}
	}
	if (u == v)
		return u;
	for (int i = LG; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[v][0];
}
int main() {
	cin >> n >> t;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int j = 1; j <= LG; j++) {
		for (int i = 1; i <= n; i++) {
			int u = par[i][j - 1];
			par[i][j] = par[u][j - 1];
		}
	}
	c[1] = true;
	bfs();
//	for (int i = 1; i <= n; i++) {
//		cout << "73 " << i << " " << dis[i] << endl;
//	}
	for (int i = 1; i <= t; i++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int v;
			cin >> v;
			qs.push_back(v);
			c[v] = true;
		}
		else {
			int v;
			cin >> v;
			int ans = dis[v];
			for (auto u : qs) {
				int w = lca(u, v);
				ans = min(ans, h[v] + h[u] - 2 * h[w]);
			}
			cout << ans << endl;
		}
		if (qs.size() == SQ) {
			qs.clear();
			bfs();
		}
	}
	return 0;
}