#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "f";

struct TEvent {
	int x, v, k, l, r, up;
	TEvent() {}
	TEvent(int x, int v, int k, int l, int r, int up): x(x), v(v), k(k), l(l), r(r), up(up) {}
};

bool operator <(const TEvent& a, const TEvent& b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.up != b.up) return a.up < b.up;
	if (mp(a.l, a.r) != mp(b.l, b.r)) return mp(a.l, a.r) < mp(b.l, b.r);
	return a.v < b.v;
}

const int NMAX = 200010;
const int MAGIC = 0;

int n, a[NMAX], ans[NMAX];
int t[4 * NMAX];
vector<TEvent> ev;

void solve_simple(int k) {
	int res = 0;
	forn(i, n) {
		if (i > 0 && a[i] < a[(i + k - 1) / k - 1])
			res++;
	}
	ans[k - 1] = res;
}

void presolve(int k) {
	int v = 0, res = 0;
	while (1) {
		int l = k * v + 1, r = k * (v + 1);
		if (l >= n)
			break;
		ev.pb(TEvent(a[v], v, k, l, r, -1));
		v++;
	}
}

void update(int v, int l, int r, int p, int zn) {
	if (l > p || r < p) return;
	if (l == r) {
		t[v] += zn;
		return;
	}
	update(2 * v, l, (l + r) >> 1, p, zn);
	update(2 * v + 1, (l + r + 2) >> 1, r, p, zn);
	t[v] = t[2 * v] + t[2 * v + 1];
}

int get(int v, int l, int r, int ll, int rr) {
	if (l > rr || ll > r) return 0;
	if (ll <= l && r <= rr) return t[v];
	return get(2 * v, l, (l + r) >> 1, ll, rr) + get(2 * v + 1, (l + r + 2) >> 1, r, ll, rr);
	t[v] = t[2 * v] + t[2 * v + 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	seta(t, 0);

	forn(i, n)
		if (i) {
			if (i <= MAGIC) solve_simple(i);
			else presolve(i);
		}
	forn(i, n)
		ev.pb(TEvent(a[i], i, -1, -1, -1, 1));
	sort(all(ev));
	forn(i, ev.size()) {
		if (ev[i].up == 1)
			update(1, 0, n - 1, ev[i].v, 1);
		else {
			ans[ev[i].k - 1] += get(1, 0, n - 1, ev[i].l, ev[i].r);
		}
	}

	forn(i, n - 1)
		printf("%d ", ans[i]);


	return 0;
}