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

using namespace std;

struct Path {
	int u, v, w;
	bool operator<(const Path &other) const {
		return w < other.w;
	}
};

int n;
const int MAX_NODES = (int)2e5 + 1;
const int MAX_ANCESTORS = log2(MAX_NODES) + 4;
vector<int> adj[MAX_NODES];
int depth[MAX_NODES] = { 0 };
vector<int> parent[MAX_NODES];

int lca(int u, int v) {
	int diff = depth[u] - depth[v];
	if (diff < 0) {
		swap(u, v);
		diff = -diff;
	}
	for(int i = 0; diff; ++i)
		if (diff & (1 << i)) {
			diff -= 1 << i;
			u = parent[u][i];
		}

	if (u == v)
		return u;

	for (int i = (int)log2(depth[u]); i >= 0; --i) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int dist(const int u, const int v) {
	return depth[u] + depth[v] - (depth[lca(u, v)] << 1);
}

// compute depth[] and parent[][]
void dfsPrec(const int u, const int p) {
	for (auto &&v : adj[u])
		if (v != p) {
			depth[v] = depth[u] + 1;
			parent[v][0] = u;
			for (int i = 1; parent[v][i - 1] > 0; ++i)
				parent[v][i] = parent[parent[v][i - 1]][i - 1];
			dfsPrec(v, u);
		}
}

void dfsPrec() { // ^^
	depth[1] = 0;
	for (int i = 1; i <= n; ++i)
		parent[i] = vector<int>(MAX_ANCESTORS, -1);
	dfsPrec(1, -1);
}

// find diameter of tree, return deepest node
int dfsDiam(int u, Path &path) {
	int best = u, secondBest = u;
	for (int v : adj[u]) {
		v = dfsDiam(v, path);
		if (depth[v] >= depth[best]) {
			secondBest = best;
			best = v;
		}
		else if (depth[v] > depth[secondBest])
			secondBest = v;
	}
	path = max(path, { secondBest, best, depth[best] + depth[secondBest] - (depth[u] << 1) });
	return best;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// input
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfsPrec();

	// remove parent from adj list
	for (int i = 2; i <= n; ++i)
		adj[i].erase(find(adj[i].begin(), adj[i].end(), parent[i][0]));
	
	Path path = { 1, 1, 0};
	dfsDiam(1, path);

	// problem-specific
	vector<int> leaves;
	for (int i = 1; i <= n; ++i)
		if (adj[i].empty() && i != path.u && i != path.v)
			leaves.push_back(i);

	long long ans = 0;
	vector<array<int, 2>> out;

	while (!leaves.empty()) {
		int u = leaves.back();
		leaves.pop_back();
		ans += max(dist(u, path.u), dist(u, path.v));
		int furthest = dist(u, path.u) > dist(u, path.v) ? path.u : path.v;
		out.push_back({ furthest, u});

		int p = parent[u][0];
		adj[p].pop_back();
		if (adj[p].empty())
			leaves.push_back(p);
	}

	if (depth[path.u] > depth[path.v])
		swap(path.u, path.v);
	
	// rem top nodes
	vector<int> top = { parent[lca(path.u, path.v)][0] };
	while (top.back() != -1)
		top.push_back(parent[top.back()][0]);
	top.pop_back();
	reverse(top.begin(), top.end());
	for (auto &&p : top) {
		ans += depth[path.v] - depth[p];
		out.push_back({ path.v, p });
	}

	// rem diameter nodes
	while (abs(depth[path.u] - depth[path.v]) != path.w) {
		ans += path.w--;
		out.push_back({ path.v, path.u });
		path.u = parent[path.u][0];
	}
	while (path.w) {
		ans += path.w--;
		out.push_back({ path.u, path.v });
		path.v = parent[path.v][0];
	}
	
	
	cout << ans;
	for (auto &&x : out)
		cout << '\n' << x[0] << ' ' << x[1] << ' ' << x[1];
	return 0;
}