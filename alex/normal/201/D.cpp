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

const int NMAX = 500100;

int num, n, m, k, d[1 << 15][120], zn[NMAX], nxt[15][NMAX];
string s;
char buf[12];
map <string, int> M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	int cnt = 0;
	forn(i, n)
	{
		cin >> s;
		M[s] = cnt++;
	}
	cin >> m;
	num = n * (n - 1) / 2 + 1;
	pii ans = mp(inf, inf);
	forn(i, m)
	{
		cin >> k;
		forn(j, k)
		{
			scanf("%s", buf);
			s = buf;
			if (!M.count(s)) M[s] = cnt++;
			zn[j] = M[s];
		}

		forn(j, n)
		{
			nxt[j][k] = inf;
			ford(f, k)
			{
				nxt[j][f] = nxt[j][f + 1];
				if (zn[f] == j) nxt[j][f] = f;
			}
		}

		forn(j, 1 << n)
			forn(f, num)
				d[j][f] = inf;
		d[0][0] = -1;
		forn(j, 1 << n)
			forn(f, num)
				if (d[j][f] < inf)
				{
					int now = 0;
					ford(g, n)
						if (!(j & (1 << g)))
							d[j | (1 << g)][f + now] = min(d[j | (1 << g)][f + now], nxt[g][d[j][f] + 1]);
						else
							now++;
				}

		forn(j, num)
			if (d[(1 << n) - 1][j] < inf && ans.fs > j)
				ans = mp(j, i);
	}
	if (ans.fs == inf) cout << "Brand new problem!" << endl;
	else
	{
		string tmp = "";
		forn(i, num - ans.fs)
			tmp += "|";
		cout << ans.sc + 1 << endl << "[:" << tmp << ":]" << endl;
	}

	return 0;
}