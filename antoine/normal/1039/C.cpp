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
#include <ctime>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct DSU {
	vector<int> rank;
	vector<int> parent;
	int numComps;

	DSU(int n) : numComps(n) {
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
		numComps--;
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

struct IdGen {
	map<int, int> mp;
	vector<int> lazy;
	void insert(int x) {
		assert(mp.empty());
		lazy.push_back(x);
	}
	void process() {
		assert(mp.empty());
		sort(lazy.begin(), lazy.end());
		lazy.erase(unique(lazy.begin(), lazy.end()), lazy.end());
		for (int i = 0; i < (int)lazy.size(); ++i)
			mp[lazy[i]] = i;
		lazy.clear();
	}
	int getId(int x) const {
		assert(lazy.empty());
		return mp.at(x);
	}
	int size() const {
		assert(lazy.empty());
		return mp.size();
	}
};


struct Edge {
	int u, v;
	ll w;
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};


//  number of components, number of distinct nodes
pair<int, int> getComps(const vector<Edge> &edges) {
	IdGen idGen;
	for (auto &&e : edges) {
		idGen.insert(e.u);
		idGen.insert(e.v);
	}
	idGen.process();
	DSU dsu(idGen.size());
	for (auto &&e : edges) {
		const int u = idGen.getId(e.u);
		const int v = idGen.getId(e.v);
		dsu.merge(u, v);
	}

	return{ dsu.numComps, idGen.size() };
}

ll modPow(ll x, ll k) {
	ll res = 1;
	for (x %= mod; k; k >>= 1) {
		if (k & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	vector<Edge> edges;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		edges.push_back({ u, v, c[u] ^ c[v] });
	}

	sort(edges.begin(), edges.end());


	ll ans = 0;
	const ll twoToTheN = modPow(2, n);

	for (int i = 0; i < m; ++i) {
		vector<Edge> view = { edges[i] };
		while (i + 1 < m && edges[i + 1].w == edges[i].w)
			view.push_back(edges[++i]);

		// cerr << "view size: " << view.size() << endl;
		assert(all_of(view.begin(), view.end(), [&view](const Edge &e) {
			return e.w == view.front().w;
		}));

		auto res = getComps(view);
		const int numComps = res.first + n - res.second;
		ans += twoToTheN - modPow(2, numComps);
		ans %= mod;
	}

	cerr << "before : " << ans << endl;
	const ll total = (1LL << k) % mod * twoToTheN % mod;
	cout << ((total - ans) % mod + mod) % mod << '\n';
	return 0;
}