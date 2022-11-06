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
const string name = "b";

int n, d[1010], zn[1010], st[1010], x, l[1010], num;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> x;
	num = 0;
	x--;
	seta(st, 0);
	forn(i, n)
	{
		scanf("%d", &zn[i]);
		zn[i]--;
		st[zn[i]]++;
	}


	int root = -1, delta = -1;
	forn(i, n)
		if (st[i] == 0)
		{
			int now = i, cnt = 0, ok = 0;
			while (now != -1)
			{
				if (now == x) root = i, delta = cnt, ok = 1;
				now = zn[now], cnt++;
			}
			if (ok) delta = cnt - delta - 1;
			if (!ok) l[num++] = cnt;
		}

	seta(d, 0);
	d[0] = 1;
	forn(i, num)
		ford(j, n)
			if (d[j]) d[j + l[i]] = 1;
	forn(i, n)
		if (d[i])
			printf("%d\n", i + delta + 1);

	return 0;
}