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
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

const int NMAX = 11;
const int VMAX = 150000;
const int p = 1000000007;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

long long k;
int n, h, t, ans;
long long delta, step;
map <pii, int> d, may, used;
pii q[VMAX];

void solve()
{
	int res = 0, tmp = d[q[h]];
	pii now1, now2;
	while (h < t && d[q[h]] == tmp)
	{
		int x = q[h].fs, y = q[h].sc, xx, yy;
		h++;
		forn(i, 8)
		{
			xx = x + dx[i], yy = y + dy[i];
			now1 = mp(x, y), now2 = mp(xx, yy);
			if (!may.count(now2) && !used.count(now2))
			{
				res++;
				d[now2] = d[now1] + 1;
				used[now2] = 1;
				q[t++] = now2;
			}
		}
	}
	step = res - delta;
	delta = res;
	if (res == 0)
	{
		cout << ans << endl;
		exit(0);
	}
	ans = (ans + res) % p;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> k >> n;
	k = k % p;
	forn(i, n)
	{
		int x, y;
		cin >> x >> y;
		may[mp(x, y)] = 0;
	}

	ans = 1;
	d[mp(0, 0)] = 0;
	used[mp(0, 0)] = 0;
	h = t = 0;
	q[t++] = mp(0, 0);
	delta = step = 0;
	for (int i = 1; i <= min((int) k, 40); ++i)
		solve();

	long long need = (k - min((int) k, 40)) % p;
	long long sum = (need * (need + 1) / 2) % p;
	cout << (ans + need * delta + sum * step) % p << endl;

	return 0;
}