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

const int NMAX = 100010;
const int P = 1000000007;

int n, cnt[NMAX], sum[NMAX];
int64 ans, calc[1000];
vector <int> now;

int64 power(int64 x, int64 st)
{
	int64 res = 1;
	while (st > 0)
	{
		if (st & 1) res = (res * x) % P;
		x = (x * x) % P;
		st >>= 1;
	}
	return res;
}

void solve(int zn)
{
	now.clear();
	for (int i = 1; i * i <= zn; ++i)
		if (zn % i == 0)
		{
			now.pb(i);
			if (i * i < zn) now.pb(zn / i);
		}
	sort(all(now));
	int num = now.size();
	seta(calc, 0);
	forn(i, num)
		if (i < num - 1) calc[i + 1] += sum[now[i]] - sum[now[i + 1]];
		else calc[i + 1] += sum[now[i]];
	int64 now1 = 1, now2 = 1;
	forn(i, num + 1)
		now1 = (now1 * power(i, calc[i])) % P;
	calc[num - 1] += calc[num];
	calc[num] = 0;
	forn(i, num)
		now2 = (now2 * power(i, calc[i])) % P;
	ans = (ans + now1 - now2 + P) % P;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	sum[NMAX - 1] = 0;
	ford(i, NMAX)
		if (i < NMAX - 1) sum[i] = sum[i + 1] + cnt[i];
	ans = 0;
	forn(i, NMAX)
		solve(i);
	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}