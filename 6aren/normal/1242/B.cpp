#include<bits/stdc++.h>
using namespace std;

int n, m, p[100005];
vector<int> g[100005], adj[100005];

int find(int x) {
	if (p[x] == x) return x;
	return (p[x] = find(p[x]));
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		g[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		g[i].push_back(n + 1);
		sort(g[i].begin(), g[i].end());
		int cur = i;
		for (auto v : g[i]) {
			if (v - cur > 1) {
				merge(i, cur + 1);
			}
			cur = v;
		}
	}
	for (int i = n; i >= 1; i--) {
		adj[i].push_back(0);
		sort(adj[i].begin(), adj[i].end());
		int cur = i;
		for (int j = (int)adj[i].size() - 1; j >= 0; j--) {
			int v = adj[i][j];
			if (cur - v > 1) {
				//cout << i << ' ' << cur - 1 << endl;
				merge(i, cur - 1);
			}
			cur = v;
		}
	}
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(find(i));
	}
	cout << s.size() - 1;
	return 0;
}