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

const string name = "c";

const int MMAX = 101;
const int NMAX = 16;

int n, m, x[MMAX], y[MMAX], used[NMAX], ans[NMAX], may[NMAX];
int64 k, d[1 << NMAX];

void good_edge(int msk, int x, int y, int msk2, int now)
{
	if (msk & (1 << x))
	{
		if ((msk2 & (1 << x)) && now < ans[x]) may[y] = 0;
		if (!(msk2 & (1 << x))) may[y] = 0;
	}
	if (msk & (1 << y))
	{
		if ((msk2 & (1 << y)) && now > ans[y]) may[x] = 0;
	}
}

int64 calc(int num)
{
	forn(i, m)
		if (ans[x[i]] != -1 && ans[y[i]] != -1 && ans[x[i]] > ans[y[i]]) return 0;

	seta(d, 0);
	int msk = (1 << num) - 1;
	d[msk] = 1;
	forn(i, (1 << n) - 1)
		if ((i & msk) == msk)
		{
			int cnt = -num;
			forn(j, n)
				if (i & (1 << j)) cnt++;

			int now = -1;
			ford(j, n)
				if (!used[j])
				{
					if (cnt == 0)
					{
						now = j;
						break;
					}
					cnt--;
				}
			assert(now != -1);

			seta(may, 1);
			forn(j, m)
				good_edge(i, x[j], y[j], msk, now);

			forn(j, n)
				if (!(i & (1 << j)) && may[j])
					d[i | (1 << j)] += d[i];
		}
	return d[(1 << n) - 1];
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> k >> m;
	forn(i, m)
	{
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	k -= 2000;

	seta(ans, 255);
	seta(used, 0);
	if (calc(0) < k)
	{
		cout << "The times have changed" << endl;
		return 0;
	}

	forn(i, n)
		forn(j, n)
			if (!used[j])
			{
				ans[i] = j;
				used[j] = 1;
				int64 tmp = calc(i + 1);
				if (tmp >= k)
					break;
				k -= tmp;
				used[j] = 0;
				ans[i] = -1;
			}

	forn(i, n)
		cout << ans[i] + 1 << " ";

	return 0;
}