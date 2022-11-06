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
const string name = "c";

vector <vector<int>> ans;
vector<int> vnow;
int zn[20], msk, n;

int check(int s)
{
	forn(i, s / 2)
		if (zn[i] != zn[s - i - 1]) return 0;
	return 1;
}

void rec(int v, int tmp, int cnt)
{
	if (tmp & ((1 << 10) - 1 - msk)) return;
	if (v == 3)
	{
		if (tmp != msk) return;
		for (int i = 1; i <= 3; ++i)
		{
			int lvl = cnt, val = 0;
			forn(j, i)
			{
				val = val * 10 + zn[i - j - 1];
				zn[lvl++] = zn[i - j - 1];
			}
			if ((i > 1 && zn[cnt] == 0) || val >= 256 || !check(lvl)) continue;
			vnow.pb(val);
			ans.pb(vnow);
			vnow.pop_back();
		}
		return;
	}
	int oldcnt = cnt, oldtmp = tmp;
	forn(i, 256)
	{
		int now = i;
		if (now >= 100) { tmp |= (1 << now/ 100); zn[cnt++] = now / 100;  now %= 100; }
		if (i >= 10) { tmp |= (1 << now / 10); zn[cnt++] = now / 10; now %= 10; }
		zn[cnt++] = now;
		tmp |= (1 << now);
		vnow.pb(i);
		rec(v + 1, tmp, cnt);
		vnow.pop_back();
		cnt = oldcnt, tmp = oldtmp;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	msk = 0;
	cin >> n;
	forn(i, n)
	{
		int d;
		cin >> d;
		msk |= (1 << d);
	}
	ans.clear();
	vnow.clear();
	rec(0, 0, 0);
	cout << ans.size() << endl;
	forn(i, ans.size())
	{
		forn(j, 4)
		{
			if (j) printf(".");
			printf("%d", ans[i][j]);
		}
		cout << endl;
	}

	return 0;
}