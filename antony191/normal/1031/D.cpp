#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

#define int ll
const int maxn = 2100;
char a[maxn][maxn];
int d[maxn][maxn], c[maxn][maxn], p[maxn][maxn];
struct biba {
	char c;
	int k;
	int i;
	biba(char _c, int _k, int _i) {
		c = _c; k = _k; i = _i;
	}
	biba() {}
};
bool operator <(const biba & a, const biba & b) {
	return a.c < b.c || (a.c == b.c && a.k < b.k);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	forn(i, n) {
		forn(j, n) {
			cin >> a[i][j];
			if (i > 0) uax(d[i][j], d[i - 1][j]);
			if (j > 0) uax(d[i][j], d[i][j - 1]);
			if (a[i][j] == 'a') d[i][j]++;
		}
	}
	int mx = -1;
	forn(i, n)
		forn(j, n) {
		if (d[i][j] + k >= i + j + 1) uax(mx, i + j);
	}
	vector<biba> tmp;
	for (int sum = n + n - 3; sum >= 0; --sum) {
		tmp.clear();
		forn(i, n) {
			int j = sum - i;
			if (j < 0 || j >= n) continue;
			int mn = inf;
			if (i < n - 1) uin(mn, c[i + 1][j]);
			if (j < n - 1) uin(mn, c[i][j + 1]);
			p[i][j] = mn;
			tmp.emplace_back(a[i][j], mn, i);
		}
		sort(all(tmp));
		forn(i, tmp.size())
			c[tmp[i].i][sum - tmp[i].i] = i;
	}
	int ans = -1;
	if (mx != -1) {
		forn(i, n) {
			int j = mx - i;
			if (j < 0 || j >= n) continue;
			if (d[i][j] + k < i + j + 1) continue;

			if (ans == -1 || (p[ans][mx - ans] > p[i][j])) ans = i;
		}
		forn(i, mx + 1) cout << 'a';
	}
	else {
		ans = mx = 0;
	}
	int i = ans, j = mx - ans;
	while (i < n && j < n) {
		if (!(i == ans && j == mx - ans && (k > 0 || a[i][j] == 'a')))
			cout << a[i][j];
		if (i == n - 1) {
			j++;
			continue;
		}
		if (j == n - 1) {
			i++;
			continue;
		}
		if (c[i + 1][j] < c[i][j + 1]) i++;
		else j++;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}