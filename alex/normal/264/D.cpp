#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
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

const int NMAX = 1001000;

int f(int c)
{
	if (c == 'R') return 0;
	if (c == 'G') return 1;
	if (c == 'B') return 2;
	assert(0);
}

int n, m, l, r, pre[NMAX][3][3];
int64 ans;
char s[NMAX], t[NMAX];

int calc(int idx, int ept)
{
	if (idx < 0 || ept == 0) return 0;
	return pre[idx][f(s[ept])][f(s[ept - 1])];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);

	seta(pre, 0);
	forn(i, m)
		if (i)
		{
			memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
			pre[i][f(t[i - 1])][f(t[i])]++;
			forn(j, 3)
				pre[i][j][j] = 0;
		}

	l = 0, r = 0;
	ans = 0;
	forn(i, n)
	{
		while (r < m - 1 && s[i] != t[r]) r++;
		ans += r - l + 1 - (calc(r, i) - calc(l - 1, i));
		if (r < m - 1) r++;
		if (s[i] == t[l]) l++;
	}
	cout << ans << endl;

	return 0;
}