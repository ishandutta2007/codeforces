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
const string name = "i";

const int NMAX = 5010;

char s[NMAX];
int n, d1[NMAX], d2[NMAX], ans[NMAX][NMAX], zn[NMAX];

int triv(int p1, int p2, int l)
{
	while (p1 - (l + 1) >= 0 && p2 + (l + 1) < n && s[p1 - (l + 1)] == s[p2 + (l + 1)])
		l++;
	return l;
}

void create_pals()
{
	int l = 0, r = -1;
//	cerr << s << endl;
//	cerr << "-------" << endl;
	forn(i, n)
	{
		if (i > r) d1[i] = triv(i, i, 0);
		else d1[i] = triv(i, i, min(d1[l + r - i], r - i));
//		cerr << i << " " << d1[i] << " ";
//		for (int j = i - d1[i]; j <= i + d1[i]; ++j)
//			cerr << s[j];
//		cerr << endl;
		if (i + d1[i] > r)
			l = i - d1[i], r = i + d1[i];
	}
//	cerr << "-------" << endl;
	l = 0, r = -1;
	forn(i, n)
	{
		if (i > r) d2[i] = triv(i, i - 1, 0);
		else d2[i] = triv(i, i - 1, min(d2[l + r - i + 1], r - i + 1));
//		cerr << i << " " << d2[i] << " ";
//		for (int j = i - d2[i]; j < i + d2[i]; ++j)
//			cerr << s[j];
//		cerr << endl;
		if (i + d2[i] > r)
			l = i - d2[i], r = i + d2[i] - 1;
	}
}

void precalc(int st)
{
	seta(zn, 0);
	for (int i = st; i < n; ++i)
	{
		int l = i - d1[i], r = i + d1[i];
		if (l < st)
		{
			r -= st - l;
			l = st;
		}
		zn[i]++, zn[r + 1]--;
	}
	for (int i = st; i < n; ++i)
	{
		int l = i - d2[i], r = i + d2[i] - 1;
		if (l < st)
		{
			r -= st - l;
			l = st;
		}
		zn[i]++, zn[r + 1]--;
	}
	int now = 0, sum = 0;
	for (int i = st; i < n; ++i)
	{
		now += zn[i];
		sum += now;
		ans[st][i] = sum;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("i.in", "r", stdin);
	freopen("i.out", "w", stdout);
#endif

	cin >> s;
	n = strlen(s);
	forn(it, n)
		create_pals();
	forn(i, n)
		precalc(i);

	int q;
	cin >> q;
	forn(i, q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		printf("%d\n", ans[l][r]);
	}

	return 0;
}