#include <iostream>
#include <vector>
using namespace std;

const int N = 2005, mod = 1000 * 1000 * 1000 + 7;
int d, n;

int a[N];
bool mark[N];
long long dp[N];
vector <int> adj[N];

void dfs(int v, int root) {
	if (a[root] - a[v] > d) {
		return;
	}
	if (a[v] > a[root] || (a[v] == a[root] && v > root) || a[root] - a[v] > d) {
		return;
	}
	mark[v] = true;
	dp[v] = 1;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u, root);
			dp[v] *= dp[u] + 1;
			dp[v] %= mod;
		}
	}
}
int main() {
	cin >> d >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(mark, mark + n + 1, false);
		fill(dp, dp + n + 1, 0);
		dfs(i, i);
		ans += dp[i];
		ans %= mod;
	//	for (int j = 1; j <= n; j++) {
	//		cout << dp[j] << " ";
	//	}
	//	cout << endl;
	}
	cout << ans << endl;
	return 0;
}