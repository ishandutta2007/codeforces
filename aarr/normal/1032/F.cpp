#include <iostream>
#include <vector>
using namespace std;

const int N = 300 * 1000 + 5, mod = 998244353;

long long dp[N][3];
int c[N];
vector <int> adj[N];
int par[N];

long long po(long long x, long long y) {
	if (y == 0) {
		return 1;
	}
	x %= mod;
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

void dfs(int v) {
	dp[v][0] = dp[v][2] = 1;
	for (auto u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			dfs(u);
			dp[v][0] *= dp[u][1] * 2 + dp[u][2];
			dp[v][2] *= dp[u][1] + dp[u][2];
			dp[v][0] %= mod;
			dp[v][2] %= mod;
		}
	}
	for (auto u : adj[v]) {
		if (u != par[v]) {
			long long x = 1ll * dp[v][0] * po(dp[u][1] * 2 + dp[u][2], mod - 2);
			x %= mod;
			x *= dp[u][0];
			x %= mod;
			dp[v][1] += x;
			dp[v][1] %= mod;
		}
	}
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
	dfs(1);
	cout << (dp[1][1] + dp[1][2]) % mod;
	return 0;
}