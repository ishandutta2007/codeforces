#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 5e3 + 9;
vector<int> adj[MxN + 9];
ll dp[MxN + 9];
int n;

int dist(const int u, const int v) {
	return (v - u + n) % n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	for (int i = 0; i < n; ++i) {
		if (adj[i].empty())
			continue;
		int d = 1 << 30;
		for (const int x : adj[i])
			d = min(d, dist(i, x));
		dp[i] = n * ((ll) adj[i].size() - 1LL) + d;
	}

	for (int i = 0; i < n; ++i) {
		ll ans = 0;
		for (int j = 0; j < n; ++j)
			if (dp[j])
				ans = max(ans, dist(i, j) + dp[j]);
		cout << ans << ' ';
	}
	return 0;
}