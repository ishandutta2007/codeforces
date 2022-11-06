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
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "d";

void no()
{
	cout << "NO" << endl;
	exit(0);
}

const int NMAX = 100010;

int n, a[NMAX], sum, cnt;
pii zn[NMAX];

void solve(int x)
{
	if (zn[x + 1].sc < zn[x].sc + 1) no();
	cnt += zn[x].sc * 2 + 1;
	zn[x + 1].sc -= zn[x].sc + 1;
	zn[x].sc = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	sum = n;
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int m = 0;
	forn(i, n)
		if (i == 0 || a[i] != a[i - 1])
			zn[m++] = mp(a[i], 1);
		else
			zn[m - 1].sc++;
	n = m;

	cnt = 0;
	forn(i, n - 1)
	{
		if (zn[i].fs + 1 != zn[i + 1].fs) no();
		zn[i].sc--;
		cnt++;
	}
	forn(i, n - 1)
		solve(i);

	if (cnt != sum) no();
	cout << "YES" << endl;

	return 0;
}