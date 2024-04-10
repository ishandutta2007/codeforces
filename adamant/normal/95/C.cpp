#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	x--, y--;
	vector<pair<int, int>> g[n];
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	int t[n], c[n];
	for(int i = 0; i < n; i++) {
		cin >> t[i] >> c[i];
	}
	vector<vector<int>> dist(n, vector<int>(n, 1e18));
	vector<pair<int, int>> G[n];
	for(int i = 0; i < n; i++) {
		dist[i][i] = 0;
		set<pair<int, int>> que = {{0, i}};
		while(!que.empty()) {
			int v = begin(que)->second;
			que.erase(begin(que));
			for(auto it: g[v]) {
				int u = it.first, c = it.second;
				if(dist[i][v] + c < dist[i][u]) {
					que.erase({dist[i][u], u});
					dist[i][u] = dist[i][v] + c;
					que.insert({dist[i][u], u});
				}
			}
		}
		for(int j = 0; j < n; j++) {
			if(dist[i][j] <= t[i]) {
				G[i].push_back({j, c[i]});
			} 
		}
	}
	vector<int> Dist(n, 1e18);
	Dist[x] = 0;
	set<pair<int, int>> que = {{0, x}};
	while(!que.empty()) {
		int v = begin(que)->second;
		que.erase(begin(que));
		for(auto it: G[v]) {
			int u = it.first, c = it.second;
			if(Dist[v] + c < Dist[u]) {
				que.erase({Dist[u], u});
				Dist[u] = Dist[v] + c;
				que.insert({Dist[u], u});
			}
		}
	}
	if(Dist[y] == 1e18) {
		cout << -1 << endl;
	} else {
		cout << Dist[y] << endl;
	}
	return 0;
}