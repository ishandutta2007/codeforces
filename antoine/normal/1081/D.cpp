#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	int size(int u) {
		return rank[find(u)];
	}
};

struct Edge {
	int u, v, w;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

const int MaxN = (int) 1e5 + 9;
int ans[MaxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> vk(k);

	for (int &x : vk) {
		cin >> x;
		ans[x] = 1;
	}

	vector<Edge> edges(m);
	for (auto &&e : edges)
		cin >> e.u >> e.v >> e.w;

	sort(edges.begin(), edges.end());

	DSU dsu(n + 1);

	for (auto &&e : edges) {
		assert(1 <= e.u && e.u <= n);
		assert(1 <= e.v && e.v <= n);
		int u = dsu.find(e.u);
		int v = dsu.find(e.v);
		if (u == v)
			continue;

		if (dsu.rank[u] < dsu.rank[v])
			swap(u, v);
		dsu.rank[u] += dsu.rank[v];
		dsu.parent[v] = u;

		ans[u] = ans[u] && ans[v] ? e.w : max(ans[u], ans[v]);
	}
	cerr << "TEST" << endl;

	for (const int &x : vk)
		cout << ans[dsu.find(x)] << ' ';
	return 0;
}