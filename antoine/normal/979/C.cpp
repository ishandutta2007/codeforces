#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;

void dfs(int u, vector<vector<int>> &adj, vector<int> &dp, vector<int> &parent) {
	for (auto &&v : adj[u])
		if (v != parent[u]) {
			parent[v] = u;
			dfs(v, adj, dp, parent);
			dp[u] += dp[v];
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	--x, --y;
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> dp(n, 1), parent(n, -1);
	dfs(x, adj, dp, parent);
	int z = y;
	while (parent[z] != x)
		z = parent[z];
	cout << (ll)n * (n - 1) - (ll)(n - dp[z]) * dp[y];
	return 0;
}