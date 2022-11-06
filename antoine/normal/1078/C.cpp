#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
const int MaxN = (int) 3e5 + 9;
vector<int> adj[MaxN + 9];
ll dp[MaxN + 9][3];

void dfs(const int u) {
	const int k = (int) adj[u].size();
	adj[u].insert(adj[u].begin(), 0);

	for (int i = 1; i <= k; ++i) {
		const int &v = adj[u][i];
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		dfs(v);
	}

	static ll cpL[MaxN + 9];
	static ll cpR[MaxN + 9];
	cpL[0] = cpR[k + 1] = 1;

	dp[u][0] = 1;

	for (int i = 1; i <= k; ++i) {
		const int &v = adj[u][i];

		cpL[i] = cpL[i - 1] * (dp[v][0] + 2 * dp[v][2]) % mod;

		dp[u][0] *= dp[v][0] + dp[v][2];
		dp[u][0] %= mod;

	}

	for (int i = k; i >= 1; --i) {
		const int &v = adj[u][i];

		cpR[i] = cpR[i + 1] * (dp[v][0] + 2 * dp[v][2]) % mod;

		dp[u][2] += (dp[v][0] + dp[v][1]) * cpL[i - 1] % mod * cpR[i + 1] % mod;
		dp[u][2] %= mod;
	}

	dp[u][1] = (cpL[k] - dp[u][0] + mod) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	const int root = 3;
	dfs(root);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			assert(0 <= dp[i][j] && dp[i][j] < mod);

	const ll ans = dp[root][0] + dp[root][2];
	cerr << dp[root][0] << ' ' << dp[root][1] << ' ' << dp[root][2] << '\n';
	cout << (ans % mod + mod) % mod;
	return 0;
}