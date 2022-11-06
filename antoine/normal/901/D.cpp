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
#include <bitset>
#include <array>

using namespace std;

int n, m;
long long c[(int)1e5 + 1];
vector<int> adj[(int)1e5 + 1];
map<pair<int, int>, long long> ans;

array<int, 2> dfs1(int u, vector<int> &dist, vector<int> &parent) {
	for (int v : adj[u])
		if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			parent[v] = u;
			auto res = dfs1(v, dist, parent);
			if (res[0] != -1)
				return res;
		}
		else if (!((dist[v] ^ dist[u]) & 1)) {
			return { u, v };
		}
	return{ -1, -1 };
}

vector<int> dfs1() {
	vector<int> dist(n + 1, -1);
	vector<int> parent(n + 1, -1);
	dist[1] = 0;
	auto uv = dfs1(1, dist, parent);
	if (uv[0] == -1)
		return{};
	int &u = uv[0];
	int &v = uv[1];
	if (dist[u] > dist[v])
		swap(u, v);
	vector<int> cycle = { u };
	for (; v != u; v = parent[v])
		cycle.push_back(v);
	return cycle;
}

void dfs2(int u, vector<bool> &visited) {
	visited[u] = true;
	for (auto &&v : adj[u])
		if (!visited[v]) {
			dfs2(v, visited);
			ans[{u, v}] += c[v];
			ans[{v, u}] += c[v];
			c[u] -= c[v];
			c[v] = 0;
		}
}

void dfs2(int root) {
	vector<bool> visited(n + 1, 0);
	dfs2(root, visited);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	vector<pair<int, int>> edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.push_back({ a, b });
	}

	auto cycle = dfs1();
	int root = cycle.empty() ? 1 : cycle[0];
	dfs2(root);
	if ((c[root] & 1) || c[root] && cycle.empty()) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < cycle.size(); ++i) {
		int u = cycle[i];
		int v = cycle[(i + 1) % cycle.size()];
		long long diff = (c[root] >> 1) * (i & 1 ? -1 : 1);
		ans[{u, v}] += diff;
		ans[{v, u}] += diff;
	}
	cout << "YES\n";
	for (auto &&x : edges)
		cout << ans[x] << '\n';
	return 0;
}