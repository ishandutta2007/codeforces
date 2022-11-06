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

int n, k;
vector<pair<int, int>> adj[(int)1e5];

int maxDist[(int)1e5];
bool added[(int)1e5];
int parent[(int)1e5];

bool noChildAdded(int u) {
	for (auto &&x : adj[u])
		if (x.first != parent[u] && added[x.first])
			return false;
	return true;
}

void dfs(int u, const int limit, vector<int> &nodes) {
	for (auto &&x : adj[u]) {
		const int &v = x.first;
		if (v == parent[u])
			continue;
		parent[v] = u;
		const int &w = x.second;
		dfs(v, limit, nodes);
		maxDist[u] = max(maxDist[u], maxDist[v] + w);
		added[v] |= maxDist[v] + w > limit;
		added[u] |= added[v];
		if (added[v] && noChildAdded(v)) nodes.push_back(v);
	}
}

bool dfs2(int u, int prev, const int dest, vector<int> &nodes) {
	nodes.push_back(u);
	if (u == dest)
		return true;
	for (auto &&x : adj[u])
		if (x.first != prev && dfs2(x.first, u, dest, nodes))
			return true;
	nodes.pop_back();
	return false;
}

bool bfs(const vector<int> startNodes, const int limit) {
	static int dist[(int)1e5];
	memset(dist, -1, sizeof dist);

	queue<int> q;
	for (auto &&x : startNodes) {
		dist[x] = 0;
		q.push(x);
	}
	while (!q.empty()) {
		const int u = q.front();
		q.pop();
		for (auto &&x : adj[u]) {
			const int v = x.first;
			const int w = x.second;
			if (dist[v] == -1) {
				dist[v] = dist[u] + w;
				if (dist[v] > limit)
					return false;
				q.push(v);
			}
		}
	}
	return true;
}


bool f(int mid) {
	memset(parent, -1, sizeof parent);
	memset(maxDist, 0, sizeof maxDist);
	memset(added, 0, sizeof added);
	
	vector<int> nodes;
	dfs(0, mid, nodes);

	if (nodes.empty())
		return true;
	
	if (nodes.size() == 1) {
		int u = nodes[0];
		nodes.clear();
		dfs2(u, -1, 0, nodes);
		while (nodes.size() > k)
			nodes.pop_back();
	}
	else if (nodes.size() == 2) {
		int u = nodes[0];
		int v = nodes[1];
		nodes.clear();
		dfs2(u, -1, v, nodes);
		if (nodes.size() > k)
			return false;
	}
	else if (nodes.size() > 2)
		return false;

	return bfs(nodes, mid);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;

	for (int i = 1; i < n; ++i) {
		int x, y, d;
		cin >> x >> y >> d;
		--x, --y;
		adj[x].emplace_back(y, d);
		adj[y].emplace_back(x, d);
	}

	int lo = 0;
	int hi = 1e9 + 2;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo;
	return 0;
}