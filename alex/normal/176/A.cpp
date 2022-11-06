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
#include <deque>

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
const string name = "a";

const int NMAX = 105;

int n, m, k, ans;
vector <int> now;
int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];

int may(int x, int y)
{
	now.clear();
	forn(i, m)
		forn(j, c[x][i])
			now.pb(b[y][i] - a[x][i]);
	sort(all(now));
	reverse(all(now));
	int res = 0;
	forn(i, min(k, (int) now.size()))
		if (now[i] <= 0) break;
		else res += now[i];
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> k;
	forn(i, n)
	{
		string tmp;
		cin >> tmp;
		forn(j, m)
			cin >> a[i][j] >> b[i][j] >> c[i][j];
	}

	ans = 0;
	forn(i, n)
		forn(j, n)
			if (i != j)
				ans = max(ans, may(i, j));
	cout << ans << endl;

	return 0;
}