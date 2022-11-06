#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 1009;
vector<int> adj[MaxN + 9];
bool visited[MaxN + 9];
int pred[MaxN + 9];

void dfs(const int u, const int parent, const int currDepth, int &maxDepth, int &deepest) {
	visited[u] = true;
	if (currDepth > maxDepth) {
		maxDepth = currDepth;
		deepest = u;
	}

	for (const int &v : adj[u])
		if (v != parent) {
			pred[v] = u;
			dfs(v, u, currDepth + 1, maxDepth, deepest);
		}
}

// maxDepth, deepest
pair<int, int> dfs(const int u) {
	int maxDepth = 0;
	int deepest = u;
	dfs(u, -1, 0, maxDepth, deepest);
	return {maxDepth, deepest};
}

// diameter length, center of diameter
pair<int, int> diam(int u) {
	u = dfs(u).second;
	pair<int, int> p = dfs(u);
	for (int rep = p.first >> 1; rep; --rep)
		p.second = pred[p.second];
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			v.push_back(diam(i));

	for (auto &&x : v) {
		ans = max(ans, x.first);
		x.first = (x.first + 1) >> 1;
	}

	sort(v.begin(), v.end());
	const int k = (int) v.size();

	if (k >= 2) {
		ans = max(ans, v[k - 2].first + 1 + v[k - 1].first);
		if (k >= 3)
			ans = max(ans, v[k - 3].first + 2 + v[k - 2].first);
	}

	cout << ans << '\n';
	for (int i = 0; i + 1 < k; ++i)
		cout << v[i].second << ' ' << v.back().second << '\n';
	return 0;
}