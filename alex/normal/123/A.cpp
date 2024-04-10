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
const string name = "a";

char s[1010], ans[1010];
int n, zn[255];
vector <pii> q;
vector <int> tmp;

int prime(int x)
{
	for (int i = 2; i < x; ++i)
		if (x % i == 0) return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> s;
	n = strlen(s);
	seta(zn, 0);
	forn(i, n)
		zn[s[i]]++;
	forn(i, 255)
		if (zn[i] > 0) q.pb(mp(zn[i], i));
	sort(all(q));
	reverse(all(q));

	tmp.pb(1);
	forn(i, n + 1)
		if (i > 1 && prime(i) && 2 * i > n)
			tmp.pb(i);
	if (q[0].fs >= n - (int) tmp.size())
	{
		cout << "YES" << endl;
		forn(i, n)
			ans[i + 1] = q[0].sc, q[0].fs--;
		forn(i, q.size())
			forn(j, q[i].fs)
			{
				ans[last(tmp)] = q[i].sc;
				tmp.pop_back();
			}
		forn(i, n)
			cout << ans[i + 1];
		cout << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}