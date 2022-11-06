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

using namespace std;
typedef long long ll;

bool dfs(const int u, vector<int> &visited, const vector<vector<int>> &adj) {
	bool res = adj[u].size() == 2;
	visited[u] = true;
	for (auto &&v : adj[u]) {
		if (adj[v].size() != 2)
			res = false;
		if (!visited[v] && !dfs(v, visited, adj))
			res = false;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	vector<int> visited(n, false);
	for (int i = 0; i < n; ++i)
		ans += !visited[i] && dfs(i, visited, adj);

	cout << ans;
	return 0;
}