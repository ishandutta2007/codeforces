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
const string name = "a";

int n, cnt[256];
char s[100100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> s;
	n = strlen(s);
	int q = 0, diff = 0;
	seta(cnt, 0);
	forn(i, n)
		if (s[i] == '?') q++;
		else cnt[s[i]] = 1;
	for (char c = 'A'; c <= 'Z'; ++c)
		if (cnt[c]) diff++;

	seta(cnt, 0);
	forn(i, q)
		cnt[10]++;
	forn(i, diff)
		cnt[10 - i]++;
	if (s[0] < '0' || s[0] > '9') cnt[10]--, cnt[9]++;

	int64 ans = 1;
	forn(i, 10)
		forn(j, cnt[i])
			ans *= i;

	cout << ans;
	forn(i, cnt[10])
		printf("0");
	cout << endl;

	return 0;
}