#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;
ll C2(ll x) {
	return x * (x - 1) / 2;
}

const int MxN = (int) 5e5 + 9;
int n;
vector<int> adj[MxN + 9];
int par[MxN + 9];
ll sz[MxN + 9];

ll dp[MxN + 9];
ll ans = 0;

void dfs(const int u) {
	sz[u] = 1;
	for (const int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		par[v] = u;
		dfs(v);
		sz[u] += sz[v];
	}

	if (adj[u].empty())
		return;

	const ll Inf = (ll) 1e15 + 9;

	dp[u] = Inf;
	for (const int v : adj[u])
		dp[u] = min(dp[u], dp[v] + C2(sz[u] - sz[v]));

	if (adj[u].size() == 1)
		return;

	sort(adj[u].begin(), adj[u].end(), [](const int x, const int y) {
		int diff = sz[x] - sz[y];
		if(diff)
		diff = dp[x] - dp[y];
		return diff < 0;
	});

	vector<int> st;

	for (const int v : adj[u]) {
		for (int w : st)
			ans = max(ans, 2 * C2(n) - dp[v] - dp[w] - C2(n - sz[v] - sz[w]));

		if (st.empty() || sz[v] > sz[st.back()])
			st.push_back(v);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	if (n == 2) {
		cout << 2;
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = C2(n);

	int root = 1;
	while (adj[root].size() <= 1)
		assert(++root <= n);
	dfs(root);

	cout << ans;
	return 0;
}