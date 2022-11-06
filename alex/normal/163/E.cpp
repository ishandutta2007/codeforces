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
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "e";

const int NMAX = 100100;
const int SMAX = 1000100;

int n, m, num, ans, vertex[NMAX], used[NMAX], cnt;
char s[SMAX];
int nxt[SMAX][27], end[SMAX], link[SMAX], _in[SMAX], _out[SMAX];
pii q[SMAX], prev[SMAX];
int fenwick[2 * SMAX];
vector <int> g[SMAX];

void update(int x, int c)
{
	while (x <= 2 * num)
	{
		fenwick[x] += c;
		x = x | (x + 1);
	}
}

int get(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += fenwick[x];
		x = (x & (x + 1)) - 1;
	}
	return res;
}

void dfs(int v)
{
	forn(i, g[v].size())
	{
		_in[g[v][i]] = cnt++;
		dfs(g[v][i]);
		_out[g[v][i]] = cnt++;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> m >> n;
	num = 1;
	seta(end, 0);
	seta(nxt, 255);
	q[0] = mp(0, 0);
	forn(i, n)
	{
		int len, v = 0;
		scanf("%s", s);
		len = strlen(s);
		forn(j, len)
		{
			if (nxt[v][s[j] - 'a'] == -1)
			{
				q[num] = mp(j + 1, num);
				prev[num] = mp(v, s[j] - 'a');
				nxt[v][s[j] - 'a'] = num;
				num++;
			}
			v = nxt[v][s[j] - 'a'];
		}
		end[v]++;
		vertex[i] = v;
	}

	sort(q, q + num);
	forn(i, num)
	{
		int v = q[i].sc;
		if (q[i].fs <= 1)
			link[v] = 0;
		else link[v] = nxt[link[prev[v].fs]][prev[v].sc];

		if (q[i].fs <= 0)
		{
			forn(j, 26)
				if (nxt[v][j] == -1) nxt[v][j] = 0;
		}
		else
		{
			forn(j, 26)
				if (nxt[v][j] == -1)
					nxt[v][j] = nxt[link[v]][j];
		}
	}

	forn(i, num)
		if (i > 0) g[link[i]].pb(i);
	cnt = 1;
	dfs(0);
	seta(used, 1);
	seta(fenwick, 0);
	forn(i, num)
		if (i > 0)
		{
			update(_in[i], end[i]);
			update(_out[i], -end[i]);
		}

	forn(i, m)
	{
		char ch = ' ';
		while (ch <= ' ')
			scanf("%c", &ch);
		if (ch == '+')
		{
			int name;
			scanf("%d", &name);
			name--;
			if (!used[name])
			{
				used[name] = 1;
				update(_in[vertex[name]], end[vertex[name]]);
				update(_out[vertex[name]], -end[vertex[name]]);
			}
		}
		if (ch == '-')
		{
			int name;
			scanf("%d", &name);
			name--;
			if (used[name])
			{
				used[name] = 0;
				update(_in[vertex[name]], -end[vertex[name]]);
				update(_out[vertex[name]], end[vertex[name]]);
			}
		}
		if (ch == '?')
		{
			ans = 0;
			int len, v = 0;
			scanf("%s", s);
			len = strlen(s);
			forn(j, len)
			{
				v = nxt[v][s[j] - 'a'];
				if (v > 0) ans += get(_in[v]);
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}