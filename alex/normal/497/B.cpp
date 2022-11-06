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
const string name = "b";

const int NMAX = 601010;
const int LOG = 17;

int n, zn[NMAX];
pii jump[LOG][NMAX];
pii ans[NMAX];

int move(int& now, int s) {
	int a = 0, b = 0;
	ford(i, LOG)
		if (max(a + jump[i][now].fs, b + jump[i][now].sc) < s) {
			a += jump[i][now].fs, b += jump[i][now].sc;
			now += (1 << i);
		}
	if (now >= n) {
		now = n + 1;
		return -1;
	}
	if (zn[now] == 1 && a == s - 1) {
		now++;
		return 1;
	}
	if (zn[now] == 2 && b == s - 1) {
		now++;
		return 2;
	}
	now = n + 1;
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	seta(jump, 0);
	cin >> n;
	forn(i, n) {
		scanf("%d", &zn[i]);
		jump[0][i] = mp(zn[i] == 1, zn[i] == 2);
	}

	forn(i, LOG)
		forn(j, n)
			jump[i + 1][j] = mp(jump[i][j].fs + jump[i][j + (1 << i)].fs, jump[i][j].sc + jump[i][j + (1 << i)].sc);

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int now = 0;
		int w1 = 0, w2 = 0, lst = 0;
		while (now < n) {
			int tp = move(now, i);
			if (tp == 1) w1++, lst = 1;
			if (tp == 2) w2++, lst = 2;
			if (tp == -1) break;
		}
		if (now == n) {
			if (w1 > w2 && lst == 1)
				ans[cnt++] = mp(w1, i);
			if (w2 > w1 && lst == 2)
				ans[cnt++] = mp(w2, i);
		}
	}

	sort(ans, ans + cnt);
	cout << cnt << endl;
	forn(i, cnt)
		printf("%d %d\n", ans[i].fs, ans[i].sc);

	return 0;
}