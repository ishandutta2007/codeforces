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

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
#define sz(s) int((s).size())

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
const string name = "d";

const int NMAX = 2014;

char s[NMAX][NMAX];
int n, m, k;
vector<int> x, y;

void maybe(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2 && k == 1 && s[x1][y1] == 'w') {
		forn(i, n) {
			printf("%s\n", s[i]);
		}
		exit(0);
	}

	int cnt = 0;
	for (int i = x1; i <= x2; ++i) {
		cnt += (s[i][y1] == 'w');
		cnt += (s[i][y2] == 'w');
	}
	for (int i = y1; i <= y2; ++i) {
		cnt += (s[x1][i] == 'w');
		cnt += (s[x2][i] == 'w');
	}
	if (s[x1][y1] == 'w') cnt--;
	if (s[x1][y2] == 'w') cnt--;
	if (s[x2][y1] == 'w') cnt--;
	if (s[x2][y2] == 'w') cnt--;
	if (cnt == k) {
		for (int i = x1; i <= x2; ++i) {
			if (s[i][y1] == '.') s[i][y1] = '+';
			if (s[i][y2] == '.') s[i][y2] = '+';
		}
		for (int i = y1; i <= y2; ++i) {
			if (s[x1][i] == '.') s[x1][i] = '+';
			if (s[x2][i] == '.') s[x2][i] = '+';
		}
		forn(i, n) {
			printf("%s\n", s[i]);
		}
		exit(0);
	}
}

int main() {
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m;
	k = 0;
	forn(i, n) {
		scanf("%s", s[i]);
		forn(j, m)
			if (s[i][j] == 'w') {
				x.pb(i);
				y.pb(j);
				k++;
			}
	}
	if (k > min(n, m) * 4) {
		cout << -1 << endl;
		return 0;
	}

	sort(all(x));
	sort(all(y));
	int dx = x[x.size() - 1] - x[0] + 1;
	int dy = y[y.size() - 1] - y[0] + 1;
	int s = max(dx, dy);
	if (dx == s) {
		forn(i, m - s + 1)
			maybe(x[0], i, x[0] + s - 1, i + s - 1);
	}
	if (dy == s) {
		forn(i, n - s + 1)
			maybe(i, y[0], i + s - 1, y[0] + s - 1);
	}
	cout << -1 << endl;	

	return 0;
}