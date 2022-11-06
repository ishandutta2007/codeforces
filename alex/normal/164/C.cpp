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
#include <deque>

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
int64 const inf64 = (int64) 4e18;
const string name = "c";

struct Tedge {
	int x, y, c, f, p;
	Tedge() {}
	Tedge(int x, int y, int c, int f, int p): x(x), y(y), c(c), f(f), p(p) {}
};

const int NMAX = 1010;
const int inf = 2000000001;

int num, ans[NMAX], n, k, x[NMAX], y[NMAX], z[NMAX];
int d[2 * NMAX], prev[2 * NMAX], seg[6 * NMAX];
Tedge edges[6 * NMAX];
vector <int> p;
vector <pii> tmp;
map <int, int> M;

void add(int x, int y, int c, int p, int tmp)
{
	seg[num] = tmp;
	edges[num++] = Tedge(x, y, c, 0, p);
	edges[num++] = Tedge(y, x, 0, 0, -p);
}

void flow()
{
	forn(i, p.size())
		d[i] = inf;
	d[0] = 0;
	while (1)
	{
		int change = 0;
		forn(i, num)
			if (edges[i].c - edges[i].f > 0 && d[edges[i].x] < inf && d[edges[i].y] > d[edges[i].x] + edges[i].p)
			{
				d[edges[i].y] = d[edges[i].x] + edges[i].p;
				prev[edges[i].y] = i;
				change = 1;
			}
		if (!change) break;
	}
}

void way(int v)
{
	if (v == 0) return;
	way(edges[prev[v]].x);
	edges[prev[v]].f++;
	edges[prev[v] ^ 1].f--;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
	{
		cin >> x[i] >> y[i] >> z[i];
		y[i] = x[i] + y[i];
		p.pb(x[i]);
		p.pb(y[i]);
		tmp.pb(mp(x[i], i));
	}
	sort(all(tmp));
	sort(all(p));
	p.resize(unique(all(p)) - p.begin());
	forn(i, p.size())
	{
		if (i < (int) p.size() - 1) add(i, i + 1, 1000000, 0, -1);
		M[p[i]] = i;
	}
	forn(j, n)
	{
		int i = tmp[j].sc;
		x[i] = M[x[i]], y[i] = M[y[i]];
		add(x[i], y[i], 1, -z[i], i);
	}
	forn(i, k)
	{
		flow();
		way(p.size() - 1);
	}
	seta(ans, 0);
	forn(i, num)
		if (edges[i].c == 1 && edges[i].f == 1) ans[seg[i]] = 1;
	forn(i, n)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}