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
const string name = "c";

const int NMAX = 200100;

int n;
long double p, q;
char s1[NMAX], s2[NMAX];
pair <int, int64> zn1[NMAX], zn2[NMAX];

void solve(int c)
{
	int now1 = 0; int64 now2 = 0;
	forn(i, n)
	{
		zn1[i] = mp(now1, now2);
		if (s2[i] == c + 'A')
		{
			now1++;
			now2 += i + 1;
		}
	}
	now1 = 0, now2 = 0;
	ford(i, n)
	{
		zn2[i] = mp(now1, now2);
		if (s2[i] == c + 'A')
		{
			now1++;
			now2 += n - i;
		}
	}
	forn(i, n)
		if (s1[i] == c + 'A')
		{
			p += (i + 1) * zn2[i].sc;
			p += (n - i) * zn1[i].sc;
			if (s2[i] == c + 'A') p += (int64) (i + 1) * (n - i);
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	scanf("%s%s", s1, s2);

	p = 0, q = 0;
	forn(i, 26)
		solve(i);
	forn(i, n)
		q += ((int64) n - i) * (n - i);
	printf("%.12lf\n", (double) (p / q));

	return 0;
}