#include <bits/stdc++.h>
using namespace std;

const int N = 500 * 1000 + 5;


vector <int> adj[N];
pair <int, int> a[N];
int c[N];
set <int> s[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		c[i] = a[i].first;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int v = a[i].second;
		for (auto u : adj[v]) {
			if (c[u] == c[v]) {
				cout << -1;
				return 0;
			}
			if (c[u] < c[v]) {
				s[v].insert(c[u]);
			}
		}
		if (s[v].size() != c[v] - 1) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i].second << " ";
	}
	return 0;
}