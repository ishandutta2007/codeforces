#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

vector <vector<int>> g;
map <pair<int, int>, int> cost;
vector <vector<int>> dp;
int n, k;

void dfs(int v, int p) {
	if (g[v].size() == 1 && p != -1) {
		return;
	}
	for (auto &to : g[v]) {
		if (to != p) {
			dfs(to, v);
		}
	}
	vector <pair<int, int>> cnt;
	for (auto &to : g[v]) {
		if (to != p) {
			cnt.pb({cost[{v, to}] + dp[to][0] - dp[to][1], to});
		}
	}
	sort(all(cnt));
	reverse(all(cnt));
	while (cnt.size() && cnt.back().fi <= 0) {
		cnt.pop_back();
	}
	set <int> with;
	for (int i = 0; i < cnt.size() && i < k - 1; i++) {
		with.insert(cnt[i].se);
	}
	for (auto &to : g[v]) {
		if (to == p) {
			continue;
		}
		if (with.find(to) != with.end()) {
			dp[v][0] += cost[{v, to}] + dp[to][0];
		} else {
			dp[v][0] += max(dp[to][0], dp[to][1]);
		}
	}
	if (cnt.size() < k) {
		dp[v][1] = dp[v][0];
		return;
	}
	with.insert(cnt[k - 1].se);
	for (auto &to : g[v]) {
		if (to == p) {
			continue;
		}
		if (with.find(to) != with.end()) {
			dp[v][1] += cost[{v, to}] + dp[to][0];
		} else {
			dp[v][1] += max(dp[to][0], dp[to][1]);
		}
	}
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int q;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		g.resize(n);
		dp.resize(n);
		for (int i = 0; i < n; i++) {
			dp[i].resize(2);
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			cost[{u - 1, v - 1}] = c;
			cost[{v - 1, u - 1}] = c;
			g[v - 1].pb(u - 1);
			g[u - 1].pb(v - 1);
		}
		dfs(0, -1);
		cout << max(dp[0][0], dp[0][1]) << "\n";
		g.resize(0);
		dp.resize(0);
	}
	return 0;
}