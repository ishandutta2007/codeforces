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
const string name = "a";

const int NMAX = 401010;

int n, num, p[NMAX], ept[NMAX][27], ans;
char s[NMAX];
vector <int> g[NMAX];
vector <char> w[NMAX];

void add(int x, int y, char z)
{
	g[x].pb(y);
	w[x].pb(z);
}

void dfs(int v, int jj)
{
	if (jj == n)
	{
		ans++;
		jj = p[jj - 1];
	}
	forn(i, g[v].size())
		dfs(g[v][i], ept[jj][w[v][i] - 'a']);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	num = n;
	forn(i, n - 1)
	{
		int now;
		scanf("%d%s", &now, s);
		now--;
		int m = strlen(s);
		forn(j, m)
		{
			if (j < m - 1)
			{
				add(now, num, s[j]);
				now = num++;
			}
			else
			{
				add(now, i + 1, s[j]);
			}
		}
	}
	scanf("%s", s);
	n = strlen(s);
	int j = 0;
	p[0] = 0;
	seta(ept, 0);
	ept[0][s[0] - 'a'] = 1;
	ept[1][s[0] - 'a'] = 1;
	ept[1][s[1] - 'a'] = 2;
	for (int i = 1; i < n; ++i)
	{
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;

		for (char c = 'a'; c <= 'z'; ++c)
		{
			int now = i + 1;
			if (c == s[now]) now++;
			else if (now > 0) now = ept[p[now - 1]][c - 'a'];
			ept[i + 1][c - 'a'] = now;
		}
	}
	ans = 0;
	dfs(0, 0);
	cout << ans << endl;

	//cerr << clock() << endl;

	return 0;
}