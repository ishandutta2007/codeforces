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
const string name = "b";

const int NMAX = 200010;

int n, m, prev[NMAX], pre[NMAX], suf[NMAX];
char s[NMAX], t[NMAX];

int exist(int l, int r)
{
	if (prev[r + 1] >= l && prev[r + 1] <= r) return 1;
	else return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	scanf("%s", s);
	scanf("%s", t);
	n = strlen(t);
	m = strlen(s);

	int now = -1;
	forn(i, m)
	{
		if (now < n - 1 && s[i] == t[now + 1]) now++;
		pre[i] = now;
	}
	now = n;
	ford(i, m)
	{
		if (now > 0 && s[i] == t[now - 1]) now--;
		suf[i] = now;
	}

	int ans = 1;
	for (char c = 'a'; c <= 'z'; ++c)
	{
		int now = -1;
		forn(i, n + 1)
		{
			prev[i] = now;
			if (t[i] == c) now = i;
		}
		forn(i, m)
			if (s[i] == c && (pre[i] < suf[i] || !exist(suf[i], pre[i])))
			{
				ans = 0;
				break;
			}
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}