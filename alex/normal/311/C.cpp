#pragma comment(linker, "/STACK:600000000")
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

const int NMAX = 101010;

int n, m, k, c[NMAX], num;
int64 h, x[NMAX], d[NMAX], may[NMAX];
set< pair<int, int> > ans;
set < pair<int64, int> > S;

void recalc()
{
	forn(i, k)
		may[i] = inf64;
	may[1] = 1;
	S.clear();
	forn(i, k)
		S.insert(mp(may[i], i));
	while (S.size() > 0)
	{
		int v = S.begin()->sc;
		S.erase(S.begin());
		forn(i, num)
			if (may[(v + d[i]) % k] > may[v] + d[i])
			{
				int u = (v + d[i]) % k;
				S.erase(mp(may[u], u));
				may[u] = may[v] + d[i];
				S.insert(mp(may[u], u));
			}
	}

	ans.clear();
	forn(i, n)
		if (may[x[i] % k] <= x[i] && c[i] >= 0)
			ans.insert(mp(-c[i], i));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> h >> n >> m >> k;
	forn(i, n)
		scanf("%I64d%d", &x[i], &c[i]);

	num = 0;
	recalc();
	forn(i, m)
	{
		int tp;
		scanf("%d", &tp);
		if (tp == 1)
		{
			scanf("%I64d", &d[num++]);
			recalc();
		}
		if (tp == 2)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			if (ans.find(mp(-c[x], x)) != ans.end())
			{
				ans.erase(mp(-c[x], x));
				c[x] -= y;
				ans.insert(mp(-c[x], x));
			}
			else
			{
				c[x] -= y;
			}
		}
		if (tp == 3)
		{
			if (ans.size() == 0) printf("%d\n", 0);
			else
			{
				printf("%d\n", -(ans.begin()->fs));
				c[ans.begin()->sc] = -1;
				ans.erase(ans.begin());
			}
		}
	}

	return 0;
}