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
const string name = "a";

vector <int64> now;
int64 n;

int may(int64 d, int ind)
{
	forn(i, ind)
		if (d % now[i] == 0) return 1;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	now.clear();
	cin >> n;
	for (int64 i = 2; i * i <= n && i < n; ++i)
		if (n % i == 0)
		{
			now.pb(i);
			if (i * i != n) now.pb(n / i);
		}
	if (now.size() == 0)
	{
		cout << 1 << endl << 0 << endl;
		return 0;
	}
	sort(all(now));
	forn(i, now.size())
		if (may(now[i], i))
		{
			cout << 1 << endl << now[i] << endl;
			return 0;
		}
	cout << 2 << endl;

	return 0;
}