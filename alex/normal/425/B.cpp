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

const int NMAX = 101;

int n, m, k;
int a[NMAX][NMAX], b[NMAX][NMAX];

int solve(int msk) {
	int cnt = 0;
	forn(i, n)
		forn(j, m)
			b[i][j] = a[i][j];
	forn(i, m)
		if (msk & (1 << i)) b[0][i] ^= 1, cnt++;

	forn(j, n) {
		int now = 0;
		forn(f, m)
			if (b[0][f] != b[j][f]) now++;
		cnt += min(now, m - now);
	}
	return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> k;
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);

	if (n < m) {
		forn(i, m)
			forn(j, m)
				if (i < j) swap(a[i][j], a[j][i]);
		swap(n, m);
	}

	if (n > k) {
		int ans = k + 1;
		forn(i, n) {
			int cnt = 0;
			forn(j, n) {
				int now = 0;
				forn(f, m)
					if (a[i][f] != a[j][f]) now++;
				cnt += min(now, m - now);
			}
			ans = min(ans, cnt);
		}
		if (ans > k) cout << -1 << endl;
		else cout << ans << endl;
		return 0;
	}

	int ans = k + 1;
	forn(i, 1 << m) {
		ans = min(ans, solve(i));
	}
	if (ans > k) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}