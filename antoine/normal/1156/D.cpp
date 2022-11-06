#include <bits/stdc++.h>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	DSU dsu0(n);
	DSU dsu1(n);

	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		(w ? dsu1 : dsu0).merge(u-1, v-1);
	}

	ll res=0;
	for(int i = 0; i < n; ++i)
		res += dsu0.size(i) * (ll)dsu1.size(i) -1;
	cout << res;
	return 0;
}