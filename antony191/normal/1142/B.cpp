#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 3e18, mod = 1000'000'007, maxn = 1e5;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));
vector<int> nth;
struct node {
	int min, l, r;
	node() { min = 0; }
};
struct Segment_Tree {
	vector<node> t;
	void build(int l, int r, int v = 1) {
		t[v].l = l, t[v].r = r;
		if (l + 1 == r) {
			t[v].min = nth[l];
		}
		else {
			int m = (l + r) >> 1;
			build(l, m, v + v);
			build(m, r, v + v + 1);
			t[v].min = min(t[v + v].min, t[v + v + 1].min);
		}
	}
	Segment_Tree(int n) {
		t.resize(4 * n);
		build(0, n);
	}
	int get(int l, int r, int v = 1) {
		if (t[v].l == l && t[v].r == r) {
			return t[v].min;
		}
		if (l >= r) return inf;
		int m = (t[v].l + t[v].r) >> 1;
		return min(get(l, min(m, r), v + v), get(max(l, m), r, v + v + 1));
	}
};
vector<int> p[18];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(n), b(m), next(n), t(m);
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
	forn(i, n - 1) {
		next[a[i]] = a[i + 1];
	}
	next[a.back()] = a[0];
	vector<int> c(n, m);
	forn(i, m) {
		cin >> b[i];
		b[i]--;
	}
	forn(i, 18) p[i].resize(m + 1);
	forn(i, 18) p[i][m] = m;
	for (int i = m - 1; i >= 0; --i) {
		p[0][i] = t[i] = c[next[b[i]]];
		c[b[i]] = i;
		for (int k = 1; k < 18; ++k) p[k][i] = p[k - 1][p[k - 1][i]];
	}
	nth.resize(m);
	forn(i, m) {
		int v = i;
		for (int k = 0; k < 18; ++k)
			if ((n - 1) & (1 << k)) v = p[k][v];
		nth[i] = v;
	}
	Segment_Tree T(m);
	vector<bool> ans(q);
	forn(i, q) {
		int l, r;
		cin >> l >> r;
		ans[i] = T.get(l - 1, r) < r;
	}
	forn(i, q) cout << (int)ans[i];
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}