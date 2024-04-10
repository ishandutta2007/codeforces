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
int const inf = (int) 2e8+1;
int64 const inf64 = (int64) 4e18;
const string name = "a";

const int NMAX = 5010;

int n, m, l[NMAX], r[NMAX], z[NMAX], tp[NMAX], lvl[NMAX], now[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		lvl[i] = inf;
	forn(i, m) {
		scanf("%d%d%d%d", &tp[i], &l[i], &r[i], &z[i]);
		l[i]--, r[i]--;
		if (tp[i] == 1) {
			for (int j = l[i]; j <= r[i]; ++j)
				now[j]+=z[i];
		}
		else {
			for (int j = l[i]; j <= r[i]; ++j)
				lvl[j] = min(lvl[j], z[i] - now[j]);
		}
	}

	forn(i, n)
		now[i] = lvl[i];
	forn(i, m) {
		if (tp[i] == 1) {
			for (int j = l[i]; j <= r[i]; ++j)
				now[j]+=z[i];
		}
		else {
			int tmp = -inf;
			for (int j = l[i]; j <= r[i]; ++j)
				tmp = max(tmp, now[j]);
			if (tmp != z[i]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	forn(i, n)
		printf("%d ", lvl[i]);

	return 0;
}