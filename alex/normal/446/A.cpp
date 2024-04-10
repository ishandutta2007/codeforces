#pragma comment(linker, "/STACK:600000000")
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

const int NMAX = 101000;

int n;
int a[NMAX], l[NMAX], r[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);

	int now = 1;
	seta(l, 0);
	seta(r, 0);
	l[0] = 1, r[n - 1] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) now++;
		else now = 1;
		l[i] = now;	
	}
	now = 1;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] < a[i + 1]) now++;
		else now = 1;
		r[i] = now;	
	}

	int ans = min(n, 2);
	forn(i, n) {
		int tmp = 0;
		if (i < n - 1) tmp++;
		ans = max(ans, l[i] + tmp);
		tmp = 0;
		if (i > 0) tmp++;
		ans = max(ans, r[i] + tmp);
	}
	for (int i = 1; i < n - 1; ++i)
		if (a[i - 1] < a[i + 1] - 1)
			ans = max(ans, l[i - 1] + r[i + 1] + 1);
	cout << ans << endl;

	return 0;
}