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
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

#define int ll

struct node {
	int l, r, sum, add;
	node() {
		sum = add = 0;
	}
};
struct Segment_Tree {
	vector<node> t;
	void build(int v, int l, int r) {
		t[v].l = l, t[v].r = r;
		if (l + 1 < r) {
			int m = (l + r) >> 1;
			build(v + v, l, m);
			build(v + v + 1, m, r);
		}
	}
	Segment_Tree(int n) {
		t.resize(4 * n);
		build(1, 0, n);
	}
	void push(int v) {
		if (t[v].l + 1 < t[v].r) {
			t[v + v].add += t[v].add;
			t[v + v + 1].add += t[v].add;
			t[v].add = 0;
		}
	}
	void add(int l, int r, int d, int v = 1) {
		if (l >= r) return;
		if (t[v].l == l && t[v].r == r) {
			t[v].add += d;
			return;
		}
		push(v);
		int m = (t[v].l + t[v].r) >> 1;
		add(l, min(m, r), d, v + v);
		add(max(m, l), r, d, v + v + 1);
	}
	int get(int pos, int v = 1) {
		if (t[v].l + 1 == t[v].r) return t[v].add;
		int m = (t[v].l + t[v].r) >> 1;
		if (pos < m) return get(pos, v + v) + t[v].add;
		return get(pos, v + v + 1) + t[v].add;
	}
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	w += 2;
	Segment_Tree t(w);
	forn(i, n) {
		int m;
		cin >> m;
		m += 2;
		vector<int> a(m);
		firn(j, m - 1) cin >> a[j];
		multiset<int> q;
		for (int j = 0; j < w / 2 && j < m - 1; ++j) {
			q.insert(a[j]);
			if (w - j < m) q.erase(q.find(a[j - (w - m) - 1]));
			t.add(j, j + 1, *q.rbegin());
		}
		q.clear();
		for (int j = w - 1; j >= w / 2 && j >= w - m + 1; --j) {
			q.insert(a[m - (w - j)]);
			if (j < m - 1) q.erase(q.find(a[j + 1]));
			t.add(j, j + 1, *q.rbegin());
		}
		q.clear();
		int mx = -inf;
		forn(j, m) uax(mx, a[j]);
		t.add(m - 1, w - m + 1, mx);
	}
	firn(i, w - 1) cout << t.get(i) << ' ';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}