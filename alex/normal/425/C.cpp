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
const string name = "c";

const int NMAX = 101010;
const int DMAX = NMAX;

int n, m, s, e, num;
int a[NMAX], b[NMAX], d[NMAX];
int lst[DMAX][320];
vector<int> idx[DMAX];

inline void move(int i, int j) {
	int color = a[i];
	int dist = d[j];
	while (lst[color][j] >= 0 && idx[color][lst[color][j]] >= dist)
		lst[color][j]--;
	if (lst[color][j] + 1 < (int) idx[color].size()) {
		if (d[j + 1] == -1) d[j + 1] = NMAX + 1;
		d[j + 1] = min(d[j + 1], idx[color][lst[color][j] + 1] + 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> s >> e;
	num = min(s / e, min(n, m));
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m) {
		scanf("%d", &b[i]);
		idx[b[i]].pb(i);
	}
	forn(i, DMAX)
		forn(j, num + 1)
			lst[i][j] = idx[i].size() - 1;

	seta(d, 255);
	d[0] = 0;
	int ans = 0;
	forn(i, n + 1)
		ford(j, num + 1)
			if (d[j] >= 0) {
				int sum = (i + d[j]) + j * e;
				if (sum <= s)
					ans = max(ans, j);
				if (i < n && j < num)
					move(i, j);
			}
	cout << ans << endl;

	return 0;
}