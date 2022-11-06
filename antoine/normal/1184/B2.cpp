#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool augmentDFS(const int u, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &match) {
	if (u == -1)
		return 1;
	if (visited[u])
		return 0;
	visited[u] = true;
	for (const int v : adj[u])
		if (augmentDFS(match[v], adj, visited, match)) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	return false;
}

pair<int, vector<int>> maxMatching(const int n, const int m, const vector<vector<int>> &adj) {
	vector<bool> visited(n);
	vector<int> match(n + m, -1);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		fill(visited.begin(), visited.end(), 0);
		res += augmentDFS(i, adj, visited, match);
	}
	return {res, match};
}

int dist[101][101];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	{
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = i == j ? 0 : INT_MAX / 4;

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			if (u != v)
				dist[u][v] = dist[v][u] = 1;
		}

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}

	int n, m, K, H;
	cin >> n >> m >> K >> H;
	vector<vector<int>> adj(n + m);

	{
		vector<array<int, 3>> left(n);
		vector<array<int, 2>> right(m);
		for (auto &&e : left)
			for (int &x : e)
				cin >> x;
		for (auto &&e : right)
			for (int &x : e)
				cin >> x;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (left[i][1] >= right[j][1] && dist[left[i][0]][right[j][0]] <= left[i][2])
					adj[i].push_back(n + j);
	}

	const int c = maxMatching(n, m, adj).first;

	ll ans = (ll) 9e18;
	for (int i = 0; i <= n; ++i)
		ans = min(ans, 1LL * H * i + 1LL * K * min(c, n - i));

	cout << ans;
	return 0;
}