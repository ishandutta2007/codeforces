#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <queue>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
#define fs first
#define sc second
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long int64;
typedef pair<int, int> pii;

const int NMAX = 201010;
const int inf = (int) 1.01e9;
const string name = "b";
const double pi = acos(-1.0);

int n, m, x[NMAX], y[NMAX], xx[NMAX], yy[NMAX];
vector<pii> top, bottom, ans;
pair<double, pii> q[NMAX];
pii p[NMAX];

void calc(const vector<pii>& ept, int x, int64& p, int64& q)
{
	p = q = 0;
	if (x <= ept[0].fs || x >= ept.back().fs) return;
	int idx = lower_bound(all(ept), mp(x, -inf)) - ept.begin() - 1;
	p = ept[idx].sc * 1LL * (ept[idx + 1].fs - ept[idx].fs) + (x - ept[idx].fs) * 1LL * (ept[idx + 1].sc - ept[idx].sc);
	q = ept[idx + 1].fs - ept[idx].fs;
}

bool throw_out(pii a, pii b, pii c)
{
	return (a.fs - b.fs) * 1LL * (c.sc - b.sc) - (c.fs - b.fs) * 1LL * (a.sc - b.sc) >= 0;
}

void create()
{
	double xx = 0, yy = 0;
	forn(i, n)
		xx += p[i].fs, yy += p[i].sc;
	xx /= n, yy /= n;
	forn(i, n)
		q[i] = mp(atan2(p[i].sc - yy, p[i].fs - xx), p[i]);
	sort(q, q + n);
	int leftmost = 0;
	forn(i, n)
		if (q[i].sc < q[leftmost].sc) leftmost = i;

	ans.clear();
	ans.pb(q[leftmost].sc);
	for (int i = 1; i <= n; ++i)
	{
		pii now = q[(leftmost + i) % n].sc;
		while (ans.size() > 1 && throw_out(ans[ans.size() - 2], ans[ans.size() - 1], now))
			ans.pop_back();
		if (i < n) ans.pb(now);
	}
}

int main () {
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n;
	forn(i, n)
		scanf("%d%d", &x[i], &y[i]);

	int leftmost = 0;
	forn(i, n)
		if (mp(x[i], -y[i]) < mp(x[leftmost], -y[leftmost])) leftmost = i;
	top.clear();
	top.pb(mp(x[leftmost], y[leftmost]));
	for (int i = (leftmost + 1) % n; x[i] > x[(i - 1 + n) % n]; i = (i + 1) % n)
		top.pb(mp(x[i], y[i]));
	if (x[(leftmost - 1 + n) % n] == x[leftmost]) leftmost = (leftmost - 1 + n) % n;
	bottom.clear();
	bottom.pb(mp(x[leftmost], y[leftmost]));
	for (int i = (leftmost - 1 + n) % n; x[i] > x[(i + 1) % n]; i = (i - 1 + n) % n)
		bottom.pb(mp(x[i], y[i]));

	cin >> m;
	forn(i, m)
		scanf("%d%d", &xx[i], &yy[i]);
	forn(i, m)
	{
		int64 p1, q1, p2, q2;
		calc(top, xx[i], p1, q1);
		calc(bottom, xx[i], p2, q2);
		if (p1 <= yy[i] * q1 || p2 >= yy[i] * q2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	forn(i, n)
		p[i] = mp(x[i], y[i]);
	forn(i, m)
		p[i + n] = mp(xx[i], yy[i]);
	n += m;
	random_shuffle(p, p + n);
	create();
	if (ans.size() != n - m)
	{
		cout << ans.size() << " " << n - m << endl;
		forn(i, ans.size())
			cout << ans[i].fs << " " << ans[i].sc << endl;
	}

	cout << "YES" << endl;

	return 0;
}