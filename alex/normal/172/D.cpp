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

const int NMAX = 10000005;

int a, n;
int zn[NMAX], days[NMAX], months[NMAX], prime[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> a >> n;
	seta(prime, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i < NMAX; ++i)
		if (prime[i])
		{
			days[i] = 1;
			months[i] = i;
			int j = 2 * i;
			while (j < NMAX)
			{
				prime[j] = 0;
				zn[j] = i;
				j += i;
			}
		}
		else
		{
			int now = i, prev = i / zn[i];
			if (now % (days[prev] * zn[now] * zn[now]) == 0)
				days[now] = days[prev] * zn[now] * zn[now], months[now] = months[prev] / zn[now];
			else
				days[now] = days[prev], months[now] = months[prev] * zn[now];
		}
	months[1] = 1, days[1] = 1;

	long long ans = 0;
	for (int i = a; i <= a + n - 1; ++i)
		ans += months[i];
	cout << ans << endl;

	return 0;
}