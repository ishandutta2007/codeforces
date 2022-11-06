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

	int n, m;
	cin >> n >> m;

	DSU dsu(n);
	for(int i = 0; i < m ;++i) {
		int k;
		cin >> k;
		vector<int> v(k);
		for(int &x :v){
			cin >> x;--x;}
		for(int i = 1; i < k; ++i)
			dsu.merge(v[i-1], v[i]);
	}
	for(int i = 0; i < n; ++i){
		cout << dsu.size(i) << ' ';
	}
	return 0;
}