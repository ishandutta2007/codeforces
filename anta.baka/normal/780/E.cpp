#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> g[200000];
vector<bool> vis;
vector<int> path;

void dfs(int v) {
	vis[v] = true;
	path.push_back(v);
	for(int to : g[v])
		if(!vis[to]) {
			dfs(to);
			path.push_back(v);
		}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis.resize(n, false);
	dfs(0);
	int c = (2 * n + k - 1) / k;
	int pt = 0;
	for(int i = 0; i < k; i++) {
		vector<int> p;
		for(int j = 0; j < c && pt != path.size(); j++) p.push_back(path[pt]), pt++;
		if(p.empty()) p.push_back(1);
		cout << p.size() << ' ';
		for(int x : p) cout << x + 1 << ' ';
		cout << '\n';
	}
}