#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

struct rec{
	int x, y;
	double p;
	rec() {}
	rec(int X, int Y, double P): x(X), y(Y), p(P) {}
};

const int NMAX = 22;
const int VMAX = (NMAX + 1) * NMAX / 2 + 1;

int n, nn, a, b, num;
vector <int> g[NMAX];
map <pii, int> M;
double p[NMAX], m[VMAX][VMAX], old[VMAX][VMAX];

int main()
{
	double start = clock();
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout); 

	cin >> n >> nn >> a >> b;
	a--, b--;
	forn(i, nn)
	{
		int x, y;
		cin >> x >> y;
		g[x - 1].pb(y - 1);
		g[y - 1].pb(x - 1);
	}
	forn(i, n)
		cin >> p[i];

	int num = 0;
	forn(i, n)
		forn(j, i + 1)
			M[mp(j, i)] = M[mp(i, j)] = num++;
	forn(i, n)
		forn(j, i + 1)
		{
			forn(ii, g[i].size() + 1)
				forn(jj, g[j].size() + 1)
				{
					double p1 = 0, p2 = 0;
					int x = -1, y = -1;
					if (ii == g[i].size()) p1 = p[i], x = i;
					else p1 = (1 - p[i]) / g[i].size(), x = g[i][ii];
					if (jj == g[j].size()) p2 = p[j], y = j;
					else p2 = (1 - p[j]) / g[j].size(), y = g[j][jj];
					m[M[mp(i, j)]][M[mp(x, y)]] += p1 * p2;
				}
		}
	forn(i, n)
	{
		forn(j, num)
			m[M[mp(i, i)]][j] = 0;
		m[M[mp(i, i)]][M[mp(i, i)]] = 1;
	}

	forn(it, inf)
	{
		if ((clock() - start) / (double) CLOCKS_PER_SEC > 1.5) break;
		forn(i, num)
			forn(j, num)
			{
				old[i][j] = m[i][j];
				if (old[i][j] < 1e-11) old[i][j] = 0;
			}
		seta(m, 0);
		forn(i, num)
			forn(j, num)
				forn(f, num)
					m[i][j] += old[i][f] * old[f][j];
	}

	double tmp = 0;
	forn(i, n)
	{
		tmp += m[M[mp(a, b)]][M[mp(i, i)]];
		printf("%.10lf ", m[M[mp(a, b)]][M[mp(i, i)]]);
	}
	cerr << tmp << endl;
	cerr << clock() << endl;

	return 0;
}