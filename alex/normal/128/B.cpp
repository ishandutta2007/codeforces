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
const string name = "b";

const int NMAX = 100100;
const int64 D = 239017;

int k, n, p[NMAX];
char s[NMAX];
int64 h[NMAX], st[NMAX];

int64 hash(int x, int d)
{
	return h[x + d] - h[x] * st[d];
}

int myless(int x, int y)
{
	int l = 0, r = min(n - x, n - y);
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (hash(x, m) == hash(y, m)) l = m;
		else r = m;
	}
	int d;
	if (hash(x, r) != hash(y, r)) d = l;
	else d = r;
	if (x + d == n) return 1;
	if (y + d == n) return 0;
	return s[x + d] < s[y + d];
}

void solve(int x, int y)
{
	if (x == 0 || hash(p[x], y + 1) != hash(p[x - 1], y + 1))
	{
		int now = x, cnt = 0;
		while (now < n && hash(p[x], y + 1) == hash(p[now], y + 1))
			now++, cnt++;
		if (cnt >= k)
		{
			forn(i, y + 1)
				printf("%c", s[p[x] + i]);
			exit(0);
		}
		else k -= cnt;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	scanf("%s%d", s, &k);
	n = strlen(s);
	if (k > ((int64) n) * (n + 1) / 2)
	{
		cout << "No such line." << endl;
		return 0;
	}
	h[0] = 0, st[0] = 1;
	forn(i, n)
	{
		h[i + 1] = h[i] * D + s[i];
		st[i + 1] = st[i] * D;
	}
	forn(i, n)
		p[i] = i;
	sort(p, p + n, myless);

	forn(i, n)
		forn(j, n - p[i])
			solve(i, j);

	return 0;
}