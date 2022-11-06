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
const string name = "a";

const int NMAX = 1001;

int n, q;
int cnt[NMAX][3][3], a[NMAX][NMAX], ept[NMAX];

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	int sum = 0;
	cin >> n;
	forn(i, n)
		forn(j, n)
			scanf("%d", &a[i][j]);
	forn(i, n) {
		seta(cnt[i], 0);
		forn(j, n)
			if (i == j) ept[i] = a[i][j];
			else cnt[i][a[i][j]][a[j][i]]++;
		sum += /*cnt[i][1][1]*/ + ept[i];
	}
	cin >> q;
	forn(i, q) {
		int tp;
		scanf("%d", &tp);
		if (tp == 3) printf("%d", sum % 2);
		else {
			int x;
			scanf("%d", &x);
			x--;
			if (tp == 1) {
				//sum -= cnt[x][1][1];
				swap(cnt[x][0][0], cnt[x][1][0]);
				swap(cnt[x][0][1], cnt[x][1][1]);
				//sum += cnt[x][1][1];
			} else {
				//sum -= cnt[x][1][1];
				swap(cnt[x][0][0], cnt[x][0][1]);
				swap(cnt[x][1][0], cnt[x][1][1]);
				//sum += cnt[x][1][1];
			}
			sum -= ept[x];
			ept[x] ^= 1;
			sum += ept[x];
		}
	}

	return 0;
}