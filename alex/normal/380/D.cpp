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
const string name = "d";

const int NMAX = 101010;

const int64 P = 1000000007;

int n, a[NMAX];
int64 st[NMAX], ans, f[NMAX];
vector<pii> now;

int64 solve_empty() {
	return st[n - 1];
}

int good(int l, int r) {
	if (l < 0 || r >= n) return 0;
	for (int i = l; i <= r; ++i)
		if (a[i] != 0) return 0;
	return 1;
}

int64 invert(int64 x) {
	int st = P - 2;
	int64 res = 1;
	while (st > 0) {
		if (st & 1) res = (res * x) % P;
		x = (x * x) % P;
		st >>= 1;
	}
	return res;
}

int64 c(int n, int k) {
	return (((f[n] * invert(f[k])) % P) * invert(f[n - k])) % P;
}

void update(int& l, int& r, int idx, int val, int64& res) {
	int already = r - l + 1;
	if (idx > r) {
		int rfree = idx - r - 1;
		int lfree = val - already - 1 - rfree;
		if (lfree < 0) {
			res = 0;
			return;
		}
		if (!good(l - lfree, l - 1) || !good(r + 1, r + rfree)) {
			res = 0;
			return;
		}
		res = (res * c(rfree + lfree, lfree)) % P;
		l -= lfree, r += rfree + 1;
	} else if (idx < l) {
		int lfree = l - idx - 1;
		int rfree = val - already - 1 - lfree;
		if (rfree < 0) {
			res = 0;
			return;
		}
		if (!good(l - lfree, l - 1) || !good(r + 1, r + rfree)) {
			res = 0;
			return;
		}
		res = (res * c(rfree + lfree, lfree)) % P;
		l -= lfree + 1, r += rfree;
	} else {
		cout << "SMTH WRONG!" << endl;
		exit(0);
	}
}

int64 solve() {
	now.clear();
	forn(i, n)
		if (a[i] > 0) now.pb(mp(a[i], i));
	sort(all(now));

	int l = now[0].sc, r = now[0].sc;
	int64 res = 1;
	for (int i = 1; i < (int) now.size(); ++i) {
		update(l, r, now[i].sc, now[i].fs, res);
		if (res == 0) break;
	}
	int lfree = l;
	int rfree = n - r - 1;
	res = (res * c(rfree + lfree, lfree)) % P;
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, NMAX)
		if (i) st[i] = (st[i - 1] * 2) % P;
		else st[i] = 1;
	forn(i, NMAX)
		if (i) f[i] = (f[i - 1] * i) % P;
		else f[i] = 1;

	cin >> n;
	int exist = 0, sum = 0;
	ans = 0;
	forn(i, n) {
		scanf("%d", &a[i]);
		if (a[i] == 1) exist = 1;
		if (a[i] > 0) sum++;
	}
	if (sum == 0) ans = solve_empty();
	else if (exist) {
		ans = solve();
	}
	else {
		int idx = -1;
		forn(i, n)
			if (a[i] > 0 && (idx == -1 || a[idx] > a[i]))
				idx = i;

		if (good(idx - a[idx] + 1, idx - 1)) {
			int now = 0;
			for (int i = idx - a[idx] + 1; i < idx; ++i)
				a[i] = ++now;
			ans += (solve() * st[a[idx] - 2]) % P;
			for (int i = idx - a[idx] + 1; i < idx; ++i)
				a[i] = 0;
		}

		if (good(idx + 1, idx + a[idx] - 1)) {
			int now = 0;
			for (int i = idx + a[idx] - 1; i > idx; --i)
				a[i] = ++now;
			ans += (solve() * st[a[idx] - 2]) % P;
			for (int i = idx + a[idx] - 1; i > idx; --i)
				a[i] = 0;
		}
	}
	cout << ans << endl;

	return 0;
}