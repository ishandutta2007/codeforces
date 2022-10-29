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
const int inf = 1e9, maxn = 1e5;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

struct node {
	ll sum;
	int mx, pos;
};
int n;
node t[maxn << 2];
vector<int> a;
inline void pr(int v) {
	t[v].sum = t[v << 1].sum + t[v << 1 | 1].sum;
	if (t[v << 1].mx > t[v << 1 | 1].mx)
		t[v].mx = t[v << 1].mx, t[v].pos = t[v << 1].pos;
	else
		t[v].mx = t[v << 1 | 1].mx, t[v].pos = t[v << 1 | 1].pos;
}
void build(int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		t[v].sum = a[tl] * 1ll;
		t[v].mx = a[tl];
		t[v].pos = tl;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v << 1, tl, m);
	build(v << 1 | 1, m + 1, tr);
	pr(v);
}
void upd_pos(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v].sum = x * 1ll;
		t[v].mx = x;
		t[v].pos = tl;
		a[tl] = x;
		return;
	}
	int m = (tl + tr) >> 1;
	if (pos <= m) upd_pos(v << 1, tl, m, pos, x);
	else upd_pos(v << 1 | 1, m + 1, tr, pos, x);
	pr(v);
}
ll getsum(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v].sum;
	int m = (tl + tr) >> 1;
	return getsum(v << 1, tl, m, l, min(m, r)) + getsum(v << 1 | 1, m + 1, tr, max(m + 1, l), r);
}
void upd(int v, int tl, int tr, int l, int r, int mod) {
	if (l > r) return;
	if (tl == l && tr == r) {
		while (t[v].mx >= mod) {
			upd_pos(1, 0, n - 1, t[v].pos, t[v].mx % mod);
		}
	}
	else {
		int m = (tl + tr) >> 1;
		upd(v << 1, tl, m, l, min(m, r), mod);
		upd(v << 1 | 1, m + 1, tr, max(m + 1, l), r, mod);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	a.resize(n);
	forn(i, n) cin >> a[i];
	build();
	while (m--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << getsum(1, 0, n - 1, l, r) << el;
			continue;
		}
		if (tp == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			upd(1, 0, n - 1, l, r, x);
			continue;
		}
		int k, x;
		cin >> k >> x;
		k--;
		upd_pos(1, 0, n - 1, k, x);
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}