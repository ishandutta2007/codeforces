#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 2e5 + 9;
vector<int> adj[MaxN + 9];
ll a[MaxN + 9];
pair<ll, ll> dp[MaxN + 9];

void dfs1(const int u) {
	dp[u] = {a[u], 0};

	for(const int &v: adj[u]) {
		adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
		dfs1(v);
		dp[u].first += dp[v].first;
		dp[u].second += dp[v].second + dp[v].first;
	}
}

void dfs2(const int u, pair<ll, ll> up) {

	up.second += up.first;

	for (const int &v : adj[u])
		dfs2(v, { up.first + (dp[u].first - dp[v].first), up.second + (dp[u].second - dp[v].second - dp[v].first) });

	dp[u].first += up.first;
	dp[u].second += up.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1);
	dfs2(1, { 0, 0 });

	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dp[i].second);
	cout << ans << '\n';
	return 0;
}