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
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n, m, k;
set<int> adj[(int)2e5];
bool removed[(int)2e5];
int remCnt = 0;

void dfs(const int u) {
	if (removed[u]) return;
	if (adj[u].size() >= k) return;
	removed[u] = true;
	++remCnt;
	for (const int &v : adj[u])
		adj[v].erase(u);
	for (const int &v : adj[u])
		dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	fill(removed, removed + n, false);

	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edges[i] = { --u, --v };
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 0; i < n; ++i)
		if (!removed[i])
			dfs(i);

	vector<int> ans(m);
	for (int i = m - 1; i >= 0; --i) {
		ans[i] = n - remCnt;
		const int &u = edges[i].first;
		const int &v = edges[i].second;
		adj[u].erase(v);
		adj[v].erase(u);
		for (int x : { u, v })
			if (!removed[x])
				dfs(x);
	}
	for (auto &&x : ans)
		cout << x << '\n';
	return 0;
}