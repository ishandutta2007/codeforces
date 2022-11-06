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

struct rec {
	int x, y, d;
	rec() {}
	rec(int X, int Y, int D): x(X), y(Y), d(D) {}
};

const int NMAX = 1010;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, used[NMAX][NMAX][4], dist[NMAX][NMAX][4], h;
char s[NMAX][NMAX];
vector <rec> S;

bool operator <(const rec &a, const rec &b)
{
	return a.x + 10000 * a.y + 100000000 * a.d < b.x + 10000 * b.y + 100000000 * b.d;
}

void add(rec a, int fg)
{
	S.pb(a);
}

rec get()
{
	return S[h++];
}

int size()
{
	return S.size() - h;
}

void update(rec a, int zn, int fg)
{
	if (!used[a.x][a.y][a.d] || dist[a.x][a.y][a.d] > zn)
	{
		dist[a.x][a.y][a.d] = zn;
		used[a.x][a.y][a.d] = 1;
		add(a, fg);
	}
}

int good(rec a)
{
	if (a.x == n - 1 && a.y == m) return 1;
	return (a.x >= 0 && a.x < n && a.y >= 0 && a.y < m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	h = 0;
	forn(i, n)
		scanf("%s", s[i]);
	S.clear();
	add(rec(0, 0, 0), -1);
	seta(used, 0);
	used[0][0][0] = 1;
	dist[0][0][0] = 0;
	while (size() > 0)
	{
		rec now = get();
		int d = dist[now.x][now.y][now.d];
		{
			rec nxt = rec(now.x + dx[now.d], now.y + dy[now.d], now.d);
			if (good(nxt))
				update(nxt, d, -1);
		}
		forn(i, 4)
		{
			rec nxt = rec(now.x + dx[i], now.y + dy[i], i);
			if (good(nxt) && s[now.x][now.y] == '#')
				update(nxt, d + 1, 1);
		}
	}
	if (!used[n - 1][m][0]) cout << -1 << endl;
	else cout << dist[n - 1][m][0] << endl;

	cerr << clock() << endl;

	return 0;
}