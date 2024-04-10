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
const string name = "e";

const int NMAX = 101010;

int ans[NMAX], n, m, a[NMAX], b[NMAX], l[NMAX], r[NMAX], k[NMAX], tp[NMAX];
set<int> S;
vector <pii> ev[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);

	forn(i, m)
	{
		scanf("%d", &tp[i]);
		if (tp[i] == 2)
		{
			int x;
			scanf("%d", &x);
			x--;
			ev[x].pb(mp(0, i));
		}
		else
		{
			scanf("%d%d%d", &l[i], &r[i], &k[i]);
			l[i]--, r[i]--;
			ev[r[i]].pb(mp(-1, i));
			ev[r[i] + k[i] - 1].pb(mp(1, i));
		}
	}
	S.clear();
	forn(i, n)
	{
		sort(all(ev[i]));
		forn(j, ev[i].size())
			if (ev[i][j].fs == 0)
			{
				set<int>::iterator it = S.lower_bound(ev[i][j].sc);
				if (it == S.begin()) ans[ev[i][j].sc] = b[i];
				else
				{
					int num = *(--it);
					ans[ev[i][j].sc] = a[l[num] + i - r[num]];
				}
			}
			else
			{
				if (ev[i][j].fs == -1) S.insert(ev[i][j].sc);
				else S.erase(ev[i][j].sc);
			}
	}
	forn(i, m)
		if (tp[i] == 2)
			printf("%d\n", ans[i]);

	return 0;
}