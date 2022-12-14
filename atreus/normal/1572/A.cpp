#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;

vector<int> g[maxn];
int mark[maxn], dp[maxn];
bool isDag = true;
vector<int> topol;

void dfs(int v) {
	mark[v] = 1;
	for (auto u : g[v]) {
		if (mark[u] == 1)
			isDag = false;
		if (!mark[u])
			dfs(u);
	}
	mark[v] = 2;
	topol.push_back(v);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			g[v].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			dfs(i);
	reverse(topol.begin(), topol.end());
	for (int i = n - 1; i >= 0; i--) {
		int v = topol[i];
		for (auto u : g[v])
			dp[v] = max(dp[v], dp[u] + (v > u));
	}
	if (!isDag)
		cout << -1 << '\n';
	else
		cout << *max_element(dp + 1, dp + n + 1) + 1 << '\n';
	//vitex
	isDag = true;
	topol.clear();
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		mark[i] = 0;
		g[i].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}