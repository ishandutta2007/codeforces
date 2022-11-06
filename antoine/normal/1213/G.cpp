#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

ll C2(ll x) {
	return x * (x - 1) / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<array<int, 3>> edges;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(array<int, 3> { w, u, v });
	}

	DSU dsu(n + 1);
	map<int, ll> mp = { { 0, 0 } };
	sort(edges.begin(), edges.end());

	ll curr = 0;
	for (const auto &e : edges) {
		const int w = e[0];
		const int u = e[1];
		const int v = e[2];
		const int sz1 = dsu.size(u);
		const int sz2 = dsu.size(v);
		assert(dsu.merge(u, v));
		curr += C2(sz1 + sz2) - C2(sz1) - C2(sz2);
		mp[w] = curr;
	}
	while (q--) {
		int w;
		cin >> w;
		auto it = mp.upper_bound(w);
		cout << prev(it)->second << ' ';
	}
	return 0;
}