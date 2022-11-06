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

const int NMAX = 10010;

int n, num, a[NMAX], ans, zn[NMAX], next[NMAX], st[NMAX], lst[NMAX];
vector <int> seg[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);

	ans = 0;
	forn(i, n)
	{
		num = 0;
		seta(st, 255);
		seta(next, 255);
		forn(j, n)
		{
			zn[num] = j;
			int tmp = max(0, j - a[j]);
			if (st[tmp] == -1) st[tmp] = num, lst[tmp] = num;
			else
			{
				next[lst[tmp]] = num;
				lst[tmp] = num;
			}
			num++;
		}
		int now = 0, idx = 0, last = -1;
		while (idx < n - 1)
		{
			now++;
			int tmp = idx;
			for (int j = last + 1; j <= tmp; ++j)
				for (int f = st[j]; f != -1; f = next[f])
					idx = max(idx, zn[f]);
			last = tmp;
		}
		ans += now;
		ford(j, n)
			a[j + 1] = a[j];
		a[0] = a[n];
	}
	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}