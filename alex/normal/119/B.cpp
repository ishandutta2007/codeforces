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
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (1 << 30) - 1;
int64 const inf64 = (1LL << 62) - 1;
const string name = "b";

int a[101], used[101];
vector <int> www;
int n, k, q, _min, _max, N;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> N;
	forn(i, n)
		cin >> a[i];

	seta(used, 0);
	cin >> q;
	k = n / N;
	_min = inf, _max = -inf;
	int cnt = 0;
	forn(i, q)
	{
		int now = 0, ok = 1;
		forn(j, k)
		{
			int tmp;
			cin >> tmp;
			tmp--;
			if (used[tmp]) ok = 0;
			used[tmp] = 1;
			now += a[tmp];
		}
		if (ok) cnt++;
		_min = min(now, _min);
		_max = max(now, _max);
	}
	forn(i, n)
		if (!used[i]) www.pb(a[i]);
	sort(all(www));

	if (cnt < N)
	{
		int now = 0;
		forn(i, k)
			now += www[i];
		_min = min(now, _min);
		_max = max(now, _max);
		now = 0;
		forn(i, k)
			now += www[www.size() - i - 1];
		_min = min(now, _min);
		_max = max(now, _max);
	}

	printf("%.10lf %.10lf\n", _min / (double) k, _max / (double) k);

	return 0;
}