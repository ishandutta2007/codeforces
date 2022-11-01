#define CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <functional>
#include <complex>
#include <array>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

struct Line {
	ll k, m;
	mutable ll p;
	bool operator < (const Line& o) const { return k < o.k; }
	bool operator < (const ll& x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	// 4 max; 4 min add(-k, -m), query still x
	const ll inf = numeric_limits<ll>::max();
	ll div(ll a, ll b) const { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({ k, m, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		if (empty()) return 0;
		assert(!empty());
		const auto& l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 1e5;

int n;
int a[N], b[N];
vi g[N];
ll ans[N];
LineContainer hull[N];
LineContainer* link[N];

void dfs(int v, int p) {
	link[v] = &hull[v];
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
			if (sz(*link[to]) > sz(*link[v])) {
				link[v] = link[to];
			}
		}
	}
	for (int to : g[v]) {
		if (to != p && link[to] != link[v]) {
			for (const Line& l : *link[to]) {
				link[v]->add(l.k, l.m);
			}
			link[to]->clear();
		}
	}
	ans[v] = -link[v]->query(a[v]);
	link[v]->add(-b[v], -ans[v]);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}