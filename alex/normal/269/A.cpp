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
const string name = "a";

int ans, n;
pii a[1001100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		scanf("%d%d", &a[i].fs, &a[i].sc);
	}
	sort(a, a + n);
	int ans2 = a[n - 1].fs + 1;
	forn(i, n)
	{
		if (i == n - 1) { ans = a[i].fs; while (a[i].sc > 1) a[i].sc = (a[i].sc + 3) / 4, ans++; break ;} 
		int now = a[i + 1].fs - a[i].fs;
		if (now <= 20)
		{
			int sum = a[i].sc;
			forn(j, now)
				sum = (sum + 3) / 4;
			a[i + 1].sc = max(a[i + 1].sc, sum);
		}
	}
	cout << max(ans2, ans) << endl;

	return 0;
}