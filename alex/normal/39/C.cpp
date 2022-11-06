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

const string task = "";

int const NMAX = 2010;
int n, w[NMAX], d[NMAX], prev[NMAX];
int x[NMAX], r[NMAX], Wans[NMAX];
pii cx[NMAX], cr[NMAX];
vector <int> ans[NMAX];
set < pair <int, pii> > s;
bool used[NMAX];

void way(int p, int num)
{
	if (num == 0) return;
	way(p, prev[num]);
	forn(i, ans[w[num - 1]].size())
		ans[p].pb(ans[w[num - 1]][i]);
}

void calc(int p)
{
	int num = 0;
	forn(i, n)
		if (cx[i].sc != p && x[cx[i].sc] - r[cx[i].sc] >= x[p] - r[p] && x[cx[i].sc] + r[cx[i].sc] <= x[p] + r[p])
			w[num++] = cx[i].sc;

	ans[p].pb(p);
	seta(d, 0);
	d[0] = 1;
	forn(i, num)
	{
		int L = i, m, R = num - 1, lvl = x[p] - r[p];
		if (i) lvl = x[w[i - 1]] + r[w[i - 1]];
		while (R - L > 1)
		{
			m = (L + R) >> 1;
			if (lvl > x[w[m]]) L = m;
			else R = m;
		}
		if (lvl <= x[w[L]]) m = L;
		else m = R;

		for (int j = m; j < num; j++)
			if (d[j + 1] < d[i] + Wans[w[j]] && (i == 0 || lvl <= x[w[j]] - r[w[j]]))
			{
				d[j + 1] = d[i] + Wans[w[j]];
				prev[j + 1] = i;
			}
	}

	int f = 0;
	forn(i, num + 1)
		if (d[i] > d[f]) f = i;
	way(p, f);
	Wans[p] = ans[p].size();
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	cout << 2000 << endl;
//	forn(i, 2000)
//		cout << rand()%100000000 << " " << 1 + rand()%1000000 << endl;
//	return 0;

	cin >> n;
	forn(i, n)
	{
		scanf("%d%d", &x[i], &r[i]);
		cx[i] = mp(x[i], i);
		cr[i] = mp(r[i], i);
	}
	x[n] = 0, r[n] = (int) 2e9;
	sort(cx, cx + n);
	sort(cr, cr + n);
	cr[n] = mp(r[n], n);

	forn(i, n + 1)
		calc(cr[i].sc);

	cout << ans[n].size() - 1 << endl;
	seta(used, 0);
	forn(i, ans[n].size())
		used[ans[n][i]] = true;
	forn(i, n)
		if (used[i]) printf("%d ", i + 1);
	cerr << clock() << endl;

	return 0;
}