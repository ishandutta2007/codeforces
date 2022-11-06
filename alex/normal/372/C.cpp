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

const int NMAX = 150001;

int n, m, d, x[NMAX], T[NMAX], b[NMAX], h, t;
int64 ans[2][NMAX];
pair<int, int64> st[NMAX];

void add(int x, int64 y) {
	st[t++] = mp(x, y);
	while (t - 1 > h && st[t - 1].sc > st[t - 2].sc) {
		st[t - 2] = st[t - 1];
		t--;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m >> d;
	forn(i, m) {
		scanf("%d%d%d", &x[i], &b[i], &T[i]);
		x[i]--;
	}

	seta(ans, 0);
	int prevtime = 0;
	forn(i, m) {
		int idx = i & 1;
		forn(j, n)
			ans[idx ^ 1][j] = -inf64;
		int dist = (int) min(n * 1ull, d * 1ull * (T[i] - prevtime));
		prevtime = T[i];
		
		h = 0, t = 0;
		forn(j, min(n, dist + 1))
			add(j, ans[idx][j]);			
		forn(j, n) {
			ans[idx ^ 1][j] = st[h].sc + b[i] - abs(j - x[i]);
			if (j - dist == st[h].fs) h++;
			if (j + dist + 1 < n)
				add(min(j + dist + 1, n - 1), ans[idx][j + dist + 1]);
		}
	}
	int64 answer = -inf64;
	forn(i, n)
		answer = max(answer, ans[m & 1][i]);
	cout << answer << endl;

	return 0;
}