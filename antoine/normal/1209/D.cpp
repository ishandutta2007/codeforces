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
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	DSU dsu(n+1);
	int ans = m;
	for(int i = 0; i < m;++i) {
		int u, v;
		cin >> u >> v;
		ans -= dsu.merge(u, v);
	}
	cout << ans;
	return 0;
}