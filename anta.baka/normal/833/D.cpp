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

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)1e5;
const int mod = (int)1e9 + 7;

struct FenwickSum {
	int n;
	vi t;
	FenwickSum(int n) : n(n), t(n, 0) {}
	void upd(int v, int x) {
		for (int i = v; i < n; i |= i + 1) {
			t[i] += x;
		}
	}
	int get(int v) {
		int ret = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			ret += t[i];
		}
		return ret;
	}
};

struct FenwickMul {
	int n;
	vi t;
	FenwickMul(int n) : n(n), t(n, 1) {}
	void upd(int v, int x) {
		for (int i = v; i < n; i |= i + 1) {
			t[i] = 1LL * t[i] * x % mod;
		}
	}
	int get(int v) {
		int ret = 1;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			ret = 1LL * ret * t[i] % mod;
		}
		return ret;
	}
};

struct Edge {
	int to, x, y, ry;
};

int n;
vector<Edge> g[N];
int ans = 1;

bool ban[N];
int sizes[N];

void calc_sizes(int v, int p) {
	sizes[v] = 1;
	for (const auto& e : g[v]) {
		if (!ban[e.to] && p != e.to) {
			calc_sizes(e.to, v);
			sizes[v] += sizes[e.to];
		}
	}
}

int get_cent(int v, int p, int n) {
	for (const auto& e : g[v]) {
		if (!ban[e.to] && p != e.to && 2 * sizes[e.to] > n) {
			return get_cent(e.to, v, n);
		}
	}
	return v;
}

struct Ver {
	int a, b, m, rm;
	bool operator < (const Ver& other) const {
		return a < other.a;
	}
};

int a[N], b[N], m[N], rm[N];
vi vb;
vector<Ver> vab;

void dfs(int v, int p) {
	for (const auto& e : g[v]) {
		if (!ban[e.to] && p != e.to) {
			a[e.to] = a[v] + (e.x ? 1 : -2);
			b[e.to] = b[v] + (e.x ? -2 : 1);
			m[e.to] = 1LL * m[v] * e.y % mod;
			rm[e.to] = 1LL * rm[v] * e.ry % mod;
			dfs(e.to, v);
		}
	}
}

void dfs1(int v, int p) {
	vab.pb({ a[v], b[v], m[v], rm[v] });
	vb.pb(b[v]);
	for (const auto& e : g[v]) {
		if (!ban[e.to] && p != e.to) {
			dfs1(e.to, v);
		}
	}
}

int pw(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return 1LL * a * pw(a, b ^ 1) % mod;
	}
	a = pw(a, b >> 1);
	return 1LL * a * a % mod;
}

void calc(int v, int sgn) {
	vab.clear();
	vb.clear();
	dfs1(v, -1);
	sort(all(vab));
	sort(all(vb));
	vb.resize(unique(all(vb)) - vb.begin());
	FenwickSum ts(sz(vb));
	FenwickMul tm(sz(vb));
	int pt = -1;
	int mul = 1;
	for (int i = sz(vab) - 1; i >= 0; i--) {
		const Ver& el = vab[i];
		while (pt < i - 1 && vab[pt + 1].a <= -el.a) {
			const Ver& to_add = vab[++pt];
			int pos = lower_bound(all(vb), to_add.b) - vb.begin();
			ts.upd(pos, 1);
			tm.upd(pos, to_add.m);
		}
		if (pt == i) {
			const Ver& to_del = vab[pt--];
			int pos = lower_bound(all(vb), to_del.b) - vb.begin();
			ts.upd(pos, -1);
			tm.upd(pos, to_del.rm);
		}
		int pos = upper_bound(all(vb), -el.b) - vb.begin() - 1;
		if (pos > -1) {
			mul = 1LL * mul * pw(el.m, ts.get(pos)) % mod * tm.get(pos) % mod;
		}
	}
	if (sgn == -1) {
		mul = pw(mul, mod - 2);
	}
	ans = 1LL * ans * mul % mod;
}

void cent_dec(int v, int p) {
	calc_sizes(v, -1);
	v = get_cent(v, -1, sizes[v]);
	ban[v] = true;
	a[v] = b[v] = 0;
	m[v] = rm[v] = 1;
	dfs(v, -1);
	calc(v, 1);
	for (const auto& e : g[v]) {
		if (!ban[e.to]) {
			calc(e.to, -1);
			cent_dec(e.to, v);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, x, y;
		cin >> u >> v >> y >> x;
		--u; --v;
		int ry = pw(y, mod - 2);
		g[u].pb({ v, x, y, ry });
		g[v].pb({ u, x, y, ry });
	}
	cent_dec(0, -1);
	cout << ans;
}