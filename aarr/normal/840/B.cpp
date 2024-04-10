#include <bits/stdc++.h>
using namespace std;

const int N = 300 * 1000 + 5;


vector <pair <int, int> > adj[N];
vector <int> ans;
int d[N];
int c[N];
bool mark[N];

void dfs(int v) {
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first, e = p.second;
		if (!mark[u]) {
			dfs(u);
			if (c[u] % 2 != d[u] && d[u] >= 0) {
				c[v]++;
				ans.push_back(e);
			}
		}
	}
}

int main() {
	int n, m, s = 0, v = 1;
	bool b = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		s += d[i];
		if (d[i] < 0) {
			b = true;
			v = i;
		}
	} 
	if (!b && s % 2) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	dfs(v);
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}