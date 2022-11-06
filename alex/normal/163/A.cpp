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

const int NMAX = 5010;
const int P = 1000000007;

int n1, n2, ans, d[NMAX][NMAX];
char s1[NMAX], s2[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	gets(s1);
	n1 = strlen(s1);
	gets(s2);
	n2 = strlen(s2);

	seta(d, 0);
	forn(i, n1)
		forn(j, n2)
			if (s1[i] == s2[j]) d[i + 1][j + 1] = 1;
	ans = P;// - (n1 + 1) * (n2 + 1);
	forn(i, n1 + 1)
	{
		forn(j, n2 + 1)
		{
			if (j < n2) d[i][j + 1] = (d[i][j + 1] + d[i][j]) % P;
			if (i < n1 && j < n2 && s1[i] == s2[j]) d[i + 1][j + 1] = (d[i][j] + d[i + 1][j + 1]) % P;
		}
		ans = (ans + d[i][n2]) % P;
	}
	cout << ans << endl;

	return 0;
}