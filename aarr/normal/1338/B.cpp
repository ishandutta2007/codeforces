#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

vector <int> adj[N];
bool mark[N];
int h[N];

void dfs(int v) {
	mark[v] = true;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int ans = n - 1;
	bool a = false, b = false;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			if (h[i] % 2) {
				a = true;
			}
			else {
				b = true;
			}
		}
		int x = 0;
		for (auto u : adj[i]) {
			if (adj[u].size() == 1) {
				x++;
			}
		}
		ans -= max(0, x - 1);
	}
	if (a && b) {
		cout << 3 << " ";
	}
	else {
		cout << 1 << " ";
	}
	cout << ans;
	return 0;
}