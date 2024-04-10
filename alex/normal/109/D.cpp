#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXT
#define prev PREV
#define y1 dksj

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int NMAX = 100010;

int n, root, a[NMAX], now[NMAX], zn[NMAX];
pii b[NMAX];
vector <pii> ans;

void solve(int p)
{
	if (b[p].sc == root) return;

	if (now[root] != p)
	{
		int tmp = zn[p], pl = now[root];
		swap(now[root], now[tmp]);
		swap(zn[p], zn[pl]);
		ans.pb(mp(p, pl));
	}

	int need = b[p].sc;
	if (now[need] != p)
	{
		int pl = now[need];
		swap(now[root], now[need]);
		swap(zn[p], zn[pl]);
		ans.pb(mp(p, pl));
	}
}

int main ()
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	cin >> n;
	int sorted = 1;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		if (i && a[i] < a[i - 1]) sorted = 0;
		now[i] = i;
		b[i] = mp(a[i], i);
	}
	if (sorted)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(b, b + n);
	forn(i, n)
		zn[i] = i;

	root = -1;
	forn(i, n)
	{
		int ok = 1, z = a[i];
		while (z > 0)
		{
			if (z % 10 != 4 && z % 10 != 7) ok = 0;
			z/=10;
		}
		if (ok) root = i;
	}
	if (root == -1)
	{
		cout << -1 << endl;
		return 0;
	}

	forn(i, n)
		solve(i);
	cout << ans.size() << endl;
	forn(i, ans.size())
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);

	return 0;
}