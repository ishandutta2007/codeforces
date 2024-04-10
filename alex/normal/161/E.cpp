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

const int NMAX = 100000;

int n, ans, p[6], prime[NMAX];
vector <vector <int> > nxt[6][6][NMAX];

int isprime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return 0;
	return 1;
}

void rec(int now)
{
	if (now == n - 1)
	{
		ans += nxt[n][n - 1][p[n - 1]].size();
		return;
	}
	//int buf[6];
	//for (int i = now; i < n; ++i)
	//	buf[i] = p[i];
	int tmp = p[now];
	forn(it, nxt[n][now][tmp].size())
	{
		int cnt = 0;
		for (int i = now; i < n; ++i)
			p[i] = 10 * p[i] + nxt[n][now][tmp][it][cnt++];
//		int ok = 1;
//		for (int i = now + 1; i < n; ++i)
//			if (nxt[n][now + 1][p[i]].size() == 0) ok = 0;
//		if (ok)
			rec(now + 1);
		for (int i = now; i < n; ++i)
			p[i] /= 10;//buf[i];
	}		
}

void solve()
{
	int now;
	cin >> now;
	int tmp = now;
	n = 0;
	while (now > 0)
	{
		p[n] = now%10;
		now /= 10;
		n++;
	}
	reverse(p, p + n);
	p[0] = tmp;

	ans = 0;
	rec(1);
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, 100000)
		if (i > 1 && isprime(i))
		{
			prime[i] = 1;
			int now = i, sz = 0;
			while (now > 0)
				now /= 10, sz++;
			now = i;
			vector <int> zn;
			int ok = 1;
			while (ok)
			{
				vector <int> buf = zn;
				if (now == 0) ok = 0;
				forn(j, 5 - sz + 1)
					if (now == 0 || j == 0)
					{
						for (int i = sz + j; i <= 5; ++i)
						{
							nxt[i][i - zn.size()][now].pb(zn);
							reverse(all(last(nxt[i][i - zn.size()][now])));
						}
						zn.pb(0);
					}
				zn = buf;
				zn.pb(now % 10);
				now /= 10;
			}
		}
		else prime[i] = 0;
	cerr << clock() << endl;

	int tst;
	cin >> tst;
	forn(i, tst)
		solve();
	cerr << clock() << endl;

	return 0;
}