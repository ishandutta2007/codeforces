#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, LG = 20;

vector <int> adj[N];
int dp[N][LG + 3];
int sz[N];
int h[N];

void dfs(int v) {
	sz[v] = 1;
	for (auto u : adj[v]) {
		if (dp[u][0] == 0) {
			dp[u][0] = v;
			h[u] = h[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
	}
}
int get_par(int v, int x) {
	for (int i = LG; i >= 0; i--) {
		if (x >= (1 << i)) {
			v = dp[v][i];
			x -= (1 << i);
		}
	}
	return v;
}
pair <int, int> lca(int u, int v) {
	if (h[u] > h[v]) {
		swap(u, v);
	}
	v = get_par(v, h[v] - h[u]);
	if (u == v) {
		return {u, v};
	}
	for (int i = LG; i >= 0; i--) {
		if (dp[v][i] != dp[u][i]) {
			v = dp[v][i];
			u = dp[u][i];
		}
	}
	return {u, v};
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[1][0] = 1;
	h[1] = 1;
	dfs(1);
	for (int j = 1; j <= LG; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << sz[i] << " " << h[i] << " " << dp[i][1] << endl;
//	}
	int q;
	cin >> q;
//	cout << get_par(3, 2) << endl;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		if (u == v) {
			cout << n << endl;
			continue;
		}
		if (h[u] == h[v]) {
			pair <int, int> p = lca(u, v);
			cout << n - sz[p.first] - sz[p.second] << endl;
		}
		else {
			if (h[u] % 2 == h[v] % 2) {
				pair <int, int> p = lca(u, v);
				int w = p.first;
				if (p.first != p.second) {
					w = dp[w][0];
				}
				if (h[u] > h[v]) {
					swap(u, v);
				}
				int d = h[v] + h[u] - 2 * h[w];
				d /= 2;
				int x = get_par(v, d), y = get_par(v, d - 1);
			//	cout << "73 " << u << " " << v << " " << w << " " << d << " " << x << " " << y << endl;
				cout << sz[x] - sz[y] << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}