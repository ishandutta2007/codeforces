#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DS {
	ll left = 0, right = 0, best = 0, total = 0;

	DS() {
	}
	DS(const ll x) {
		left = right = best = max(0LL, x);
		total = x;
	}

	DS(const DS ds1, const DS ds2) {
		left = max(ds1.left, ds1.total + ds2.left);
		right = max(ds2.right, ds2.total + ds1.right);
		total = ds1.total + ds2.total;
		best = max(max(ds1.total, ds2.total), ds1.right + ds2.left);
	}
};

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
	ll A;
	cin >> n >> A;

	vector<ll> c(n), d(n);
	for (int i = 0; i < n; ++i)
		cin >> d[i] >> c[i];

	for (ll &x : c)
		x = A - x;

	adjacent_difference(d.begin(), d.end(), d.begin());
	d[0] = 0;

	vector<pair<ll, int>> merges;
	for (int i = 1; i < n; ++i)
		merges.push_back( { d[i], i });

	sort(merges.begin(), merges.end());

	ll ans = max(0LL, *max_element(c.begin(), c.end()));

	vector<DS> ds(n);
	for (int i = 0; i < n; ++i)
		ds[i] = DS(c[i]);

	DSU dsu(n);

	cerr << ans << endl;
	for (pair<ll, int> &p : merges) {
		const int u = dsu.find(p.second - 1);
		const int v = dsu.find(p.second);
		DS newDS = DS(ds[u], ds[v]);
		dsu.merge(u, v);
		ds[dsu.find(u)] = newDS;
		ans = max(ans, newDS.best - p.first * (ll)p.first);
	}
	cout << ans;
	return 0;
}