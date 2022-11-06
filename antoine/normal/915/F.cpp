#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

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

	void merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
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

int n;

long long f(vector<Edge> &edges) {
	sort(edges.begin(), edges.end());
	DSU dsu(n);
	long long ans = 0;
	for (auto &&e : edges) {
		if (dsu.find(e.u) != dsu.find(e.v)) {
			ans += (long long)e.w * dsu.size(e.u) * dsu.size(e.v);
			dsu.merge(e.u, e.v);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<Edge> edges;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		edges.push_back({ x, y, max(a[x], a[y]) });
	}

	long long ans = f(edges);
	for (auto &&e : edges)
		e.w = -min(a[e.u], a[e.v]);
	ans += f(edges);
	cout << ans;
	return 0;
}