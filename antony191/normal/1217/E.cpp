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

struct node {
	int l, r, v;
	int mn, mn2;
	node() { l = r = v = -1, mn = mn2 = inf; }
};
inline int min2(node &a, node &b) {
	int ans = max(a.mn, b.mn);
	uin(ans, a.mn2); uin(ans, b.mn2);
	return ans;
}
struct Segment_Tree {
	vector<node> t;
	void build(int v, int l, int r, vector<int> &a) {
		t[v].v = v, t[v].l = l, t[v].r = r;
		if (l + 1 == r) {
			t[v].mn = a[l];
			t[v].mn2 = inf;
			return;
		}
		int m = (l + r) >> 1;
		build(v + v, l, m, a); build(v + v + 1, m, r, a);
		t[v].mn = min(t[v + v].mn, t[v + v + 1].mn);
		t[v].mn2 = min2(t[v + v], t[v + v + 1]);
	}
	Segment_Tree(vector<int> &a) {
		t.resize(4 * a.size());
		build(1, 0, (int)a.size(), a);
	}
	Segment_Tree() {}
	void upd(int pos, int d, int v = 1) {
		if (t[v].l + 1 == t[v].r) {
			t[v].mn = d;
		}
		else {
			int m = (t[v].l + t[v].r) >> 1;
			if (pos < m) upd(pos, d, v + v);
			else upd(pos, d, v + v + 1);
			t[v].mn = min(t[v + v].mn, t[v + v + 1].mn);
			t[v].mn2 = min2(t[v + v], t[v + v + 1]);
		}
	}
	pair<int, int> get(int l, int r, int v = 1) {
		if (l >= r) return { inf, inf };
		if (t[v].l == l && t[v].r == r) return { t[v].mn, t[v].mn2 };
		int m = (t[v].l + t[v].r) >> 1;
		auto p = get(l, min(m, r), v + v), q = get(max(m, l), r, v + v + 1);
		p.y = min(max(p.x, q.x), min(p.y, q.y));
		p.x = min(p.x, q.x);
		return p;
	}
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	forn(i, n) cin >> a[i];
	Segment_Tree t[9];
	int tmp = 1;
	forn(i, 9) {
		forn(j, n) {
			if ((a[j] / tmp) % 10) b[j] = a[j];
			else b[j] = inf;
		}
		tmp *= 10;
		t[i] = Segment_Tree(b);
	}
	forn(i, m) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, d;
			cin >> i >> d;
			i--;
			tmp = 1;
			forn(j, 9) {
				if ((d / tmp) % 10) t[j].upd(i, d);
				else t[j].upd(i, inf);
				tmp *= 10;
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			l--; r--;
			auto ans = 2 * inf;
			forn(i, 9) {
				auto p = t[i].get(l, r + 1);
				if (p.y < inf) uin(ans, p.x + p.y);
			}
			if (ans >= 2 * inf) cout << -1 << el;
			else cout << ans << el;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}