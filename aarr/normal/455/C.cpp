#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 300 * 1000 + 5;

int par[N];
int dis[N];
bool mark[N];
int ans[N];
int d[N];
int cnt[N];
vector <int> adj[N];
queue <int> q;

void dfs(int v, int root) {
	if (mark[v])
		return;
	mark[v] = true;
	par[v] = root;
	for (auto u : adj[v]) {
		dfs(u, root);
	}
}
int get_par(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get_par(par[v]);
}
int main() {
	ios :: sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() <= 1) {
			q.push(i);
		}
		else {
			dis[i] = N;
		}
	}
	while (q.size()) {
		int v = q.front();
		q.pop();
		bool b = true, c = false;
		for (auto u : adj[v]) {
			cnt[u]++;
		//	cout << "48 " << v << " " << u << " " << cnt[u] << endl;
			if (cnt[u] + 1 == adj[u].size()) {
				dis[u] = dis[v] + 1;
				q.push(u);
			}
			if (dis[u] > dis[v] || (dis[u] == dis[v] && u > v)) {
				b = false;
			}
			if (dis[u] == dis[v]) {
				c = true;
			}
		}
		if (b) {
		//	cout << "73 " << v << " " << c << endl;
		//	for (int i = 1; i <= n; i++) {
		//		cout << dis[i] << " ";
		//	}
		//	cout << endl;
			dfs(v, v);
			if (c) {
				ans[v] = 2 * dis[v] + 1;
				d[v] = dis[v];
				d[v]++;
			}
			else {
				ans[v] = 2 * dis[v];
				d[v] = dis[v];
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << dis[i] << " ";
//	}
//	cout << endl;
	for (int i = 0; i < t; i++) {
		int qt, v, u = 0;
		cin >> qt >> v;
		
		if (qt == 2) {
			cin >> u;
			u = get_par(u);
			v = get_par(v);
		//	cout << "49 " << v << " " << u << " " << d[v] << " " << d[u] << endl;
			if (v == u) {
				continue;
			}

			ans[v] = max(ans[v], d[v] + d[u] + 1);
			ans[u] = max(ans[u], ans[v]);
			ans[v] = max(ans[u], ans[v]);
			int x = d[v];
			d[v] = max(d[v], d[u] + 1);
			d[u] = max(d[u], x + 1);
			if (d[u] < d[v]) {
				par[v] = u;
			}
			else {
				par[u] = v;
			}
		}
		else {
			cout << ans[get_par(v)] << '\n';
		}
	}
	return 0;
}