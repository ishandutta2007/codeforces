#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const long long INF = 1e18;
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int leaf = 0;
	for (int i = 1; i < n; ++i) {
		leaf += (int)g[i].size() == 1;
	}
	long long ans;
	if (leaf <= k) {
		ans = -INF;
		for (int i = leaf; i <= k; ++i) {
			ans = max(ans, 1ll * i * (n - i));
		}
	} else {
		vector<priority_queue<int>> dp(n); 
		function<void(int, int)> dfs = [&](int u, int p) {
			dp[u].push(0);
			for (int v : g[u]) {
				if (v != p) {
					dfs(v, u);
					if (dp[u].size() < dp[v].size()) {
						dp[u].swap(dp[v]);
					}
					while (!dp[v].empty()) {
						dp[u].push(dp[v].top());
						dp[v].pop();
					}
				}
			}
			int x = dp[u].top();
			dp[u].pop();
			dp[u].push(x + 1);
		};
		dfs(0, -1);
		int top = n;
		for (int i = 0; i < k; ++i) {
			top -= dp[0].top();
			dp[0].pop();
		}
		ans = INF;
		for (int i = 0; i <= top; ++i) {
			ans = min(ans, 1ll * (n - k - i) * (k - i));
		}
	}
	cout << ans << '\n';
	return 0;
}