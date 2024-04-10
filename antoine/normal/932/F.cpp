#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 61;
bool cmpA;
struct Line { // ax+b. xl = the x-coord of intersection with previous line in set
	ll a, b;
	mutable long double xl;
	bool operator <(const Line &l) const {
		if (cmpA)
			return a < l.a;
		else
			return xl < l.xl;
	}
};
struct Hull: multiset<Line> {
	iterator prev(iterator y) {
		return --y;
	} // skip if using c++0x/c++11
	iterator next(iterator y) {
		return ++y;
	} // skip if using c++0x/c++11
	bool bad(iterator y) {
		iterator z = next(y), x;
		if (y == begin()) {
			if (z == end())
				return 0;
			return y->a == z->a && y->b <= z->b;
		}
		x = prev(y);
		if (z == end())
			return y->a == x->a && y->b <= x->b;
		return 1.0L * (x->b - y->b) * (z->a - y->a)
				>= 1.0L * (y->b - z->b) * (y->a - x->a);
	}
	void add(ll a, ll b) { // add a line ax+b to the convex hull
		a = -a, b = -b;
		cmpA = 1;
		iterator y = insert((Line ) { a, b, -INF });
		if (bad(y)) {
			erase(y);
			return;
		}
		while (next(y) != end() && bad(next(y)))
			erase(next(y));
		while (y != begin() && bad(prev(y)))
			erase(prev(y));

		if (next(y) != end())
			next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);

		if (y != begin())
			y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
	}
	ll eval(ll x) { // find max ax+b, over all lines added, for given x
		if (empty())
			return INF;
		cmpA = 0;
		iterator it = prev(lower_bound((Line ) { 0, 0, 1.0L * x }));
		return -(it->a * x + it->b);
	}
};

// :41
int n;
ll a[(int) 1e5 + 9];
ll b[(int) 1e5 + 9];
vector<int> adj[(int) 1e5 + 9];
ll ans[(int)1e5 + 9];

Hull * merge(Hull * h1, Hull * h2) {
	if (!h1)
		return h2;
	if (!h2)
		return h1;
	if (h1->size() < h2->size())
		swap(h1, h2);
	for (auto &&x : *h2)
		h1->add(-x.a, -x.b);
	return h1;
}

Hull * dfs(const int u, const int parent) {
	if (adj[u].size() == 1 && u != 1) {
		assert(adj[u][0] == parent);
		auto hull = new Hull();
		hull->add(b[u], 0);
		return hull;
	}
	Hull * hull = nullptr;
	for (const int &v : adj[u])
		if (v != parent)
			hull = merge(hull, dfs(v, u));

	ans[u] = hull->eval(a[u]);
	hull->add(b[u], ans[u]);
	return hull;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}