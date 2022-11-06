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
const string name = "a";

int n, ans;
vector <int> tmp;
vector <int> zn[1000100];

int solve(int x, int y)
{
//	if (abs(x - y) & 1) return 0;
	int xx = 0, yy = 0, res = 0;
	int last = -1, tp = -1;
	if (zn[x][0] > zn[y][0]) tp = 1;
	else tp = 2;
	while (xx < (int) zn[x].size() || yy < (int) zn[y].size())
	{
		if (tp != 1)
		{
			if (xx == (int) zn[x].size()) break;
			if (last < zn[x][xx]) res++, last = zn[x][xx], tp = 1;
			xx++;
			continue;
		}
		if (tp != 2)
		{
			if (yy == (int) zn[y].size()) break;
			if (last < zn[y][yy]) res++, last = zn[y][yy], tp = 2;
			yy++;
			continue;
		}
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		zn[x].pb(i);
		tmp.pb(x);
	}
	sort(all(tmp));
	tmp.resize(unique(all(tmp)) - tmp.begin());
	ans = 0;
	forn(i, tmp.size())
		forn(j, i)
			ans = max(ans, solve(tmp[j], tmp[i]));
	forn(i, tmp.size())
		ans = max(ans, (int) zn[tmp[i]].size());
	cout << ans << endl;

	return 0;
}