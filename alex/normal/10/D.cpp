#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < double, double >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 510;
int n, m, k, a[NMAX], b[NMAX];
int next[NMAX][NMAX], d[NMAX][NMAX];

void way(int x, int y)
{
	if (y == 0) return;
	int w;
	for (w = 0; w < x; w++)
		if (a[w] < a[x] && d[w][y - 1] < d[x][y])
			break;
	way(w, y - 1);
	printf("%d ", a[x]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	cin >> m;
	forn(i, m)
		scanf("%d", &b[i]);

	forn(i, n)
		forn(j, m + 1)
		{
			next[i][j] = m;
			for (int f = j; f < m; f++)
				if (a[i] == b[f])
				{
					next[i][j] = f;
					break;
				}
		}

	k = min(n, m);
	forn(i, n)
		forn(j, k + 1)
			d[i][j] = m;
	forn(i, n)
		d[i][1] = next[i][0];

	forn(i, n)
		forn(j, k)
			if (d[i][j] < m)
				for (int f = i + 1; f < n; f++)
					if (a[f] > a[i])
						d[f][j + 1] = min(d[f][j + 1], next[f][d[i][j] + 1]);

	int p1 = 0, p2 = 0;

	forn(j, k + 1)
		forn(i, n)
			if (d[i][j] < m) 
				p1 = i, p2 = j;

	cout << p2 << endl;
	way(p1, p2);

	return 0;
}