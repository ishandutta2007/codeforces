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
#define hash HASHMY

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "d";

const int NMAX = 101001;
const int MAGIC = 316;
const int HMAX = 1000007;
const int D = 100239;

pii zero;
int n, x[NMAX], y[NMAX], ans, intx[NMAX], inty[NMAX];
vector< pair<pii, int> > p;
pii used[HMAX];

inline int hash(const pii& p) {
	return ((HMAX + p.fs) * 1LL * D + (HMAX + p.sc)) % HMAX;
}

inline void add(const pii& p) {
	int hv = hash(p);
	while (used[hv] != zero) {
		hv++;
		if (hv == HMAX) hv = 0;
	}
	used[hv] = p;
}

inline int find(const pii& p) {
	int hv = hash(p);
	while (used[hv] != zero) {
		if (used[hv] == p) return 1;
		hv++;
		if (hv == HMAX) hv = 0;
	}
	return 0;
}

void solve(int l, int r) {
	int value = p[l].fs.fs;
	if (r - l + 1 <= MAGIC) {
		for (int i = l; i <= r; ++i)
			for (int j = i + 1; j <= r; ++j) {
				if (find(mp(x[p[i].sc], y[p[j].sc])) &&
					find(mp(x[p[j].sc], y[p[i].sc])))
						ans++;
			}
		return;
	}

	for (int i = l; i <= r; ++i) {
		intx[x[p[i].sc]] = 1;
		inty[y[p[i].sc]] = 1;
	}
	int now = -(r - l + 1);
	forn(i, n)
		if (intx[x[i]] && inty[y[i]] && find(mp(y[i] + value, x[i] - value))) now++;
	now /= 2;
	ans += now;

	for (int i = l; i <= r; ++i) {
		intx[x[p[i].sc]] = 0;
		inty[y[p[i].sc]] = 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

/*	cout << 100000 << endl;
	forn(i, 100000)
		cout << rand() << " " << rand() << endl;
	return 0;*/

/*	cout << 316 * 316 << endl;
	forn(i, 316)
		forn(j, 316)
			cout << i << " " << j << endl;
	return 0;*/

/*	int yl = 0;
	n = 316 * 316;
	forn(i, 316)
		forn(j, 316) {
			x[yl] = i;
			y[yl] = j;
			yl++;
		}*/

	zero = mp(-1, -1);
	forn(i, HMAX)
		used[i] = zero;
	seta(intx, 0);
	seta(inty, 0);

	cin >> n;
	forn(i, n) {
		scanf("%d%d", &x[i], &y[i]);
		p.pb(mp(mp(x[i] - y[i], x[i] + y[i]), i));
		add(mp(x[i], y[i]));
	}
	sort(all(p));
	ans = 0;

	int lst = 0;
	forn(i, p.size())
		if (i != 0 && p[i].fs.fs != p[i - 1].fs.fs) {
			solve(lst, i - 1);
			lst = i;
		}
	solve(lst, n - 1);

	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}