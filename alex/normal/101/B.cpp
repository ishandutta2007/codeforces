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

const string name = "b";

const int NMAX = 200010;
const int P = 1000000007;

int n, m, num;
int q[NMAX], l[NMAX], r[NMAX], ans[NMAX], sum[NMAX];
map <int, int> M;
vector <int> g[NMAX];

int get(int ind)
{
	if (ind < 0) return 0;
	else return sum[ind];
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	forn(i, m)
	{
		scanf("%d%d", &l[i], &r[i]);
		q[2 * i] = l[i];
		q[2 * i + 1] = r[i];
	}
	sort(q, q + 2 * m);
	num = unique(q, q + 2 * m) - q;
	forn(i, num)
		M[q[i]] = i;
	forn(i, m)
		g[M[r[i]]].pb(M[l[i]]);

	seta(ans, 0);
	ans[0] = sum[0] = 1;
	forn(i, num)
		if (i)
	{
	//	sort(all(g[i]));
	//	g[i].resize(unique(all(g[i])) - g[i].begin());
		forn(j, g[i].size())
			ans[i] = (ans[i] + (get(i - 1) - get(g[i][j] - 1) + P) % P) % P;
		sum[i] = (get(i - 1) + ans[i]) % P;
	}
	if (q[0] != 0 || num == 0 || q[num - 1] != n) cout << 0 << endl;
	else cout << ans[num - 1] << endl;

	return 0;
}