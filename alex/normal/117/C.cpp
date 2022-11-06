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
const string name = "c";

const int NMAX = 5010;
int n, used[NMAX], h[NMAX], color[NMAX], p[NMAX];
char s[NMAX][NMAX];

void dfs(int v, int tmp)
{
	color[v] = 1;
	used[v] = 1;
	h[v] = tmp;
	forn(i, n)
		if (s[v][i] == '1')
		{
			if (!used[i]) dfs(i, tmp + 1);
			else
			{
				if (color[i] == 1 && tmp == h[i] + 2)
				{
					forn(j, n)
						if (s[i][j] == '1' && s[j][v] == '1')
						{
							cout << i + 1 << " " << j + 1 << " " << v + 1 << endl;
							exit(0);
						}
					cout << -1 << endl;
					exit(1);
				}
			}
		}
	color[v] = -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);
#endif

	seta(color, 0);
	cin >> n;
	forn(i, n)
	{
		cin >> s[i];
		p[i] = i;
	}

	forn(it, 10)
	{
		random_shuffle(p, p + n);
		seta(used, 0);
		forn(i, n)
			if (!used[p[i]])
				dfs(p[i], 0);
	}

	cout << -1 << endl;
	cerr << clock() << endl;

	return 0;
}