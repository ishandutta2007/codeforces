#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;
int k, n;
long long g, b;

vector <pair <int, int> > adj[N];
bool mark[N];
int dp[N];
//set <pair <int, int> > s;


void dfs(int v) {
	mark[v] = true;
	dp[v] = 1;
	for (auto p : adj[v]) {
		int u = p.first, w = p.second;
		if (!mark[u]) {
			dfs(u);
			b += 1ll * min(dp[u], n - dp[u]) * w;
			dp[v] += dp[u];
			if (dp[u] % 2 == 1) {
				g += w;
			}
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> k;
		n = 2 * k;
		for (int i = 1; i < n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		g = 0, b = 0;
		dfs(1);
		cout << g << " " << b << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
			mark[i] = false;
		}
	}
	return 0;
}