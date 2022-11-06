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
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "d";

const int NMAX = 20100;
int n, ans, a[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
    freopen((name + ".in").data(), "r", stdin);
    freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	ans = 0;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		ans += a[i];
	}

	for (int i = 1; i <= n / 3; ++i)
		if (n % i == 0)
			forn(j, i)
			{
				int now = 0, num = n / i;
				forn(f, num)
					now += a[j + f * i];
				ans = max(ans, now);
			}
	cout << ans << endl;

    return 0;
}