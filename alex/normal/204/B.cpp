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
const string name = "b";

map <int, int> M1, M2;
int n, ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		{ if (M1.count(x)) M1[x]++; else M1[x] = 1; }
		{ if (!M2.count(x)) M2[x] = 0; }
		if (x != y)
		{
			{ if (!M1.count(y)) M1[y] = 0; }
			{ if (M2.count(y)) M2[y]++; else M2[y] = 1; }
		}
	}
	ans = inf;
	for (map <int, int> :: iterator it = M1.begin(); it != M1.end(); ++it)
	{
		int now = it->sc + M2[it->fs];
		if (now >= (n + 1) / 2) ans = min(ans, max(0, (n + 1) / 2 - it->sc));
	}
	if (ans < inf) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}