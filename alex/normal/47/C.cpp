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
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int p[10], l[10], ll[10], xans, yans;
char ww[10][100], w[10][100], ans[100][100];
vector < vector <char> > answer, tmp;

void solve()
{
	if (w[0][0] != w[1][0]) return;
	if (w[4][l[4] - 1] != w[5][l[5] - 1]) return;
	if (w[0][l[0] - 1] != w[2][0]) return;
	if (w[1][l[1] - 1] != w[3][0]) return;
	if (w[2][l[2] - 1] != w[5][0]) return;
	if (w[3][l[3] - 1] != w[4][0]) return;

	if (l[1] >= l[2] || l[0] >= l[3] || w[2][l[1] - 1] != w[3][l[0] - 1]) return;

	if (l[0] + l[5] != l[3] + 1) return;
	if (l[1] + l[4] != l[2] + 1) return;

	forn(i, l[2])
		forn(j, l[3])
			ans[i][j] = '.';

	forn(i, l[0])
		ans[0][i] = w[0][i];
	forn(i, l[1])
		ans[i][0] = w[1][i];
	forn(i, l[2])
		ans[i][l[0] - 1] = w[2][i];
	forn(i, l[3])
		ans[l[1] - 1][i] = w[3][i];
	forn(i, l[4])
		ans[l[1] + i - 1][l[3] - 1] = w[4][i];
	forn(i, l[5])
		ans[l[2] - 1][l[0] + i - 1] = w[5][i];

	tmp.clear();
	tmp.resize(l[2]);
	forn(i, l[2])
	{
		forn(j, l[3])
			tmp[i].pb(ans[i][j]);
	}
	if (xans == -1 || tmp < answer)
	{
		answer = tmp;
		xans = l[2];
		yans = l[3];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	forn(i, 6)
	{
		cin >> ww[i];
		ll[i] = strlen(ww[i]);
	}

	xans = -1;
	forn(i, 6)
		p[i] = i;
	do
	{
		forn(i, 6)
		{
			l[p[i]] = ll[i];
			forn(j, ll[i] + 1)
				w[p[i]][j] = ww[i][j];
		}
		solve();
	}
	while (next_permutation(p, p + 6));

	if (xans > -1)
	{
		forn(i, xans)
		{
			forn(j, yans)
				cout << answer[i][j];
			cout << endl;
		}
		return 0;
	}

	cout << "Impossible" << endl;

	return 0;
}