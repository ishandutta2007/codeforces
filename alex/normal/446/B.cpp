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

const int NMAX = 1010000;

int n, m, p, k;
int64 ans;
int64 col[NMAX], raw[NMAX];
int64 solve_col[NMAX], solve_raw[NMAX];
multiset<int64> S;

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> k >> p;
	forn(i, n)
		forn(j, m) {
			int x;
			scanf("%d", &x);
			raw[i] += x;
			col[j] += x;
		}

	// ===============
	forn(i, n)
		S.insert(raw[i]);
	int64 now = 0;
	forn(i, k + 1) {
		solve_raw[i] = now;
		int64 ept = *S.rbegin();
		now += ept;
		S.erase(S.find(ept));
		S.insert(ept - p * m);
	}

	// ===============
	S.clear();
	forn(i, m)
		S.insert(col[i]);
	now = 0;
	forn(i, k + 1) {
		solve_col[i] = now;
		int64 ept = *S.rbegin();
		now += ept;
		S.erase(S.find(ept));
		S.insert(ept - p * n);
	}

	ans = -inf64;
	forn(i, k + 1)
		ans = max(ans, solve_raw[i] + solve_col[k - i] - i * 1LL * p * 1LL * (k - i));
	cout << ans << endl;

	cerr << clock() << endl;

	return 0;
}