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
typedef pair <int64, int> pii;
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
const string name = "a";

const int NMAX = 201010;

int n, m, yl;
int pre[NMAX], num[NMAX], elem[NMAX], buf[NMAX], tp[NMAX], ans[NMAX];
pii zn[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> m;
	forn(i, m) {
		scanf("%d", &tp[i]);
		if (tp[i] == 1) scanf("%d", &elem[i]);
		else scanf("%d%d", &pre[i], &num[i]);
	}
	cin >> n;
	forn(i, n) {
		scanf("%I64d", &zn[i].fs);
		zn[i].fs--;
		zn[i].sc = i;
	}
	sort(zn, zn + n);

	yl = 0;
	int64 now = 0;
	forn(i, m) {
		if (tp[i] == 1) {
			while (yl < n && now + 1 > zn[yl].fs) {
				ans[zn[yl].sc] = elem[i];
				yl++;
			}
			if (now < NMAX)
				buf[now] = elem[i];
			now++;
		} else {
			int tmp = pre[i] * num[i];
			while (yl < n && now + tmp > zn[yl].fs) {
				ans[zn[yl].sc] = buf[(zn[yl].fs - now) % pre[i]];
				yl++;
			}
			forn(it, tmp)
				if (now + it >= NMAX) break;
				else buf[now + it] = buf[it % pre[i]];
			now += tmp;
		}
	}

	forn(i, n)
		printf("%d ", ans[i]);

	return 0;
}