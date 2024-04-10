#pragma comment(linker, "/STACK:600000000")
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
const string name = "c";

const int NMAX = 1000010;

int n, q, l[NMAX], r[NMAX];
pii save[NMAX];
char s[NMAX];
int t[5 * NMAX];

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = save[l].fs - save[l].sc;
		return;
	}
	build(2 * v, l, (l + r) >> 1);
	build(2 * v + 1, (l + r + 2) >> 1, r);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int ll, int rr) {
	if (l > rr || ll > r)
		return inf;
	if (ll <= l && r <= rr)
		return t[v];
	int a = get(2 * v, l, (l + r) >> 1, ll, rr);
	int b = get(2 * v + 1, (l + r + 2) >> 1, r, ll, rr);
	return min(a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, 5 * NMAX)
		t[i] = inf;
	scanf("%s", s);
	n = strlen(s);
	int a = 0, b = 0;
	forn(i, n) {
		save[i] = mp(a, b);
		if (s[i] == '(') a++;
		else b++;
	}
	save[n] = mp(a, b);
	build(1, 1, n);

	cin >> q;
	forn(i, q) {
		scanf("%d%d", &l[i], &r[i]);
		int ept = get(1, 1, n, l[i], r[i]) - (save[l[i] - 1].fs - save[l[i] - 1].sc);
		printf("%d\n", 2 * (save[r[i]].sc - save[l[i] - 1].sc + min(ept, 0)));
	}

	return 0;
}