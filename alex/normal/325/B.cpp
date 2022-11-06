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
const string name = "b";

int64 n;
vector<int64> maybe;

int calc(int64 m)
{
	int64 res = 0;
	while (m % 2 == 0)
	{
		res += m / 2;
		m /= 2;
	}
	res += m * (m - 1) / 2;
	return res == n;
}

void solve(int64 ept)
{
	long double a, b, c;
	a = 0.5;
	b = ept - 1.5;
	c = -n;
//	cerr << a << " "<< b << " " << c << endl;
	if (b * b < 4 * a * c - 1e-3) return;
	long double d = sqrtl(b * b - 4 * a * c);
	long double x1 = ept * (-b - d) / 2 / a;
	long double x2 = ept * (-b + d) / 2 / a;
	maybe.pb(x1 - 1);
	maybe.pb(x1);
	maybe.pb(x1+ 1);
	maybe.pb(x2 - 1);
	maybe.pb(x2);
	maybe.pb(x2+ 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	maybe.clear();
	forn(i, 60)
		solve(1LL << i);
	sort(all(maybe));
	maybe.resize(unique(all(maybe)) - maybe.begin());
	int ans = 0;
	forn(i, maybe.size())
		if (maybe[i] > 0 && calc(maybe[i]))
		{
			cout << maybe[i] << endl;
			ans++;
		}
	if (ans == 0) cout << -1 << endl;

	return 0;
}