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
const string name = "d";

struct str {
	int d, x, y;
	str() {}
	str(int d, int x, int y): d(d), x(x), y(y) {}
};

bool operator <(str &a, str &b)
{
	if (a.x > a.y) swap(a.x, a.y);
	if (b.x > b.y) swap(b.x, b.y);
	if (a.d != b.d) return a.d < b.d;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool operator ==(str &a, str &b)
{
	if (a.x > a.y) swap(a.x, a.y);
	if (b.x > b.y) swap(b.x, b.y);
	return a.d == b.d && a.x == b.x && a.y == b.y;
}

const int NMAX = 1010;
const int KMAX = 51;

int n, k, num, x[NMAX], y[NMAX], ans[NMAX];
int used[NMAX], buf[NMAX][KMAX], cnt[NMAX];
vector <str> tmp, zn;
vector <int> calc[NMAX];

int dist(int a, int b)
{
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int rec(int now, int cnt)
{
	while (now < num && (used[zn[now].x] || used[zn[now].y]))
		now++;
	if (now == num)
	{
		forn(i, n)
			if (!used[i] && cnt < k)
				used[i] = 1, ans[cnt++] = i;
		return 1;
	}
	int tmp = 0;
	forn(i, calc[zn[now].x].size())
		if (!used[calc[zn[now].x][i]])
			buf[now][tmp++] = calc[zn[now].x][i];
	if (cnt + tmp <= k)
	{
		forn(i, tmp)
			used[buf[now][i]] = 1, ans[cnt + i] = buf[now][i];
		if (rec(now + 1, cnt + tmp)) return 1;
		forn(i, tmp)
			used[buf[now][i]] = 0;
	}
	if (tmp > 1 && cnt + 1 <= k)
	{
		used[zn[now].x] = 1;
		ans[cnt] = zn[now].x;
		if (rec(now + 1, cnt + 1)) return 1;
		used[zn[now].x] = 0;
	}
	return 0;
}

int may(int lvl)
{
	forn(i, n)
		calc[i].clear();
	num = zn.size();
	forn(i, zn.size())
		if (zn[i].d > lvl)
		{
			calc[zn[i].x].pb(zn[i].y);
			calc[zn[i].y].pb(zn[i].x);
		}
		else
		{
			num = i;
			break;
		}
	if (num == zn.size()) return 0;
	seta(used, 0);
	return rec(0, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> k;
	forn(i, n)
		cin >> x[i] >> y[i];

	zn.clear();
	forn(i, n)
		forn(j, i)
			tmp.pb(str(dist(i, j), i, j));
	sort(all(tmp));
	reverse(all(tmp));
	seta(cnt, 0);
	forn(i, tmp.size())
		if (cnt[tmp[i].x] <= k && cnt[tmp[i].y] <= k)
		{
			if (zn.size() == (k + 1) * (k + 1)) break;
			zn.pb(tmp[i]);
			cnt[tmp[i].x]++;
			cnt[tmp[i].y]++;
		}
	int l = 0, r = 2 * 32000 * 32000 + 1;
	while (l < r)
	{
		int m = (int) (((int64) l + r) >> 1);
		if (may(m)) r = m;
		else l = m + 1;
	}
	may(l);
	forn(i, k)
		cout << ans[i] + 1 << " ";
	cout << endl;

	return 0;
}