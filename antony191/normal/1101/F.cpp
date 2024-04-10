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
const ll llinf = 3e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int maxn = 400;
int a[maxn][maxn][maxn], b[maxn];
void solve(int n) {
	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			int k = j;
			a[i][j][0] = b[j] - b[i];
			for (int t = 1; t < n; ++t) {
				a[i][j][t] = max(b[k] - b[i], a[k][j][t - 1]);
				while (k > i + 1 && max(b[k - 1] - b[i], a[k - 1][j][t - 1]) <= a[i][j][t]) {
					k--;
					a[i][j][t] = max(b[k] - b[i], a[k][j][t - 1]);
				}
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) cin >> b[i];
	solve(n);
	ll ans = 0;
	forn(i, m) {
		int s, f, c, r;
		cin >> s >> f >> c >> r;
		s--; f--;
		uin(r, n - 1);
		uax(ans, a[s][f][r] * 1ll * c);
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}