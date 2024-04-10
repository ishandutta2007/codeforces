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

const int NMAX = 100010;
pair <int, string> q[NMAX];
int n, m, ind;
int p[NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	forn(i, n)
	{
		char tmp[30];
		scanf("%s%d", tmp, &q[i].fs);
		q[i].fs = -q[i].fs;
		q[i].sc = tmp;
	}
	sort(q, q + n);

	cin >> m;
	forn(i, m)
		scanf("%d", &p[i]);
	forn(i, n - m)
		p[i + m] = 0;
	sort(p, p + n);

	char tmp[30];
	cin >> tmp;

	forn(i, n)
	{
		if (q[i].sc == tmp)
			ind = i;
		q[i].fs = -q[i].fs;
	}

	int yl = ind - 1, ans1 = ind;
	for (int now = ind - 1; now >= 0; now--) {
		while (yl >= 0 && mp(- q[ind].fs - p[n - 1], q[ind].sc) > mp(- q[now].fs - p[yl], q[now].sc))
			yl--;
		if (yl >= 0)
			ans1--, yl--;
	}

	int ans2 = ind;
	yl = ind + 1;
	for (int now = ind + 1; now < n; now++) {
		while (yl < n && mp(- q[ind].fs - p[0], q[ind].sc) < mp(- q[now].fs - p[yl], q[now].sc))
			yl++;
		if (yl < n)
			ans2++, yl++;
	}

	cout << ans1 + 1 << " " << ans2 + 1 << endl;

	return 0;
}