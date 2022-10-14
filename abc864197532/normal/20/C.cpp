#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

struct Dijkstra {
	vector <vector <pair<int, long long>>> adj;
	vector <long long> dis;
	vector <int> path;
	Dijkstra (int n) {
		adj.resize(n, {});
		dis.resize(n, LLONG_MAX);
		path.resize(n, -1);
	}
	void add_edge(int u, int v, long long w) {
		adj[u-1].push_back({v-1, w});
		adj[v-1].push_back({u-1, w});
	}
	void build_dis(int s) {
		priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair <long long, int>>> q;
		q.push({0, s});
		dis[s] = 0;
		long long d;
		int v;
		while (q.size()) {
			tie(d, v) = q.top(); q.pop();
			if (d > dis[v]) continue;
			for (auto i : adj[v]) {
				if (dis[i.first] > d + i.second) {
					dis[i.first] = d + i.second;
					path[i.first] = v;
					q.push({dis[i.first], i.first});
				}
			}
		}
	}
};

int main () {
	int n,m,u,v;
	long long w;
	cin >> n >> m;
	Dijkstra dij(n);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		dij.add_edge(u, v, w);
	}
	dij.build_dis(0);
	if (dij.path[n - 1] == -1) {
		cout << -1 << endl;
	} else {
		vector <int> ans;
		u = n - 1;
		while (u != -1) {
			ans.push_back(u + 1);
			u = dij.path[u];
		}
		for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << " \n"[i == 0];
	}
}