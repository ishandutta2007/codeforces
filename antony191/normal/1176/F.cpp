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
const ll llinf = 1e18, mod = 998244353, md = 998244352;
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
const int maxn = 200'228;
vector<ll> a[maxn][3];
ll dp[maxn][10], b[maxn][3][2];
void solve(int i) {
	if (!a[i][2].empty()) uax(b[i][0][0], a[i][2][0]);
	if (!a[i][1].empty()) uax(b[i][0][0], a[i][1][0]);
	if (!a[i][0].empty()) uax(b[i][0][0], a[i][0][0]);
	if (a[i][0].size() >= 2) uax(b[i][1][0], a[i][0][0] + a[i][0][1]);
	if (a[i][0].size() >= 3) uax(b[i][2][0], a[i][0][0] + a[i][0][1] + a[i][0][2]);
	if (!a[i][0].empty() && !a[i][1].empty()) uax(b[i][1][0], a[i][0][0] + a[i][1][0]);
	b[i][0][1] = 2ll * b[i][0][0];
	b[i][2][1] = (a[i][0].size() >= 3 ? b[i][2][0] + a[i][0][0] : 0);
	if (a[i][0].size() >= 2) uax(b[i][1][1], a[i][0][0] * 2ll + a[i][0][1]);
	if (!a[i][0].empty() && !a[i][1].empty()) uax(b[i][1][1], a[i][0][0] + a[i][1][0] + max(a[i][0][0], a[i][1][0]));
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	forn(i, n) {
		int k;
		cin >> k;
		forn(j, k) {
			ll c, d;
			cin >> c >> d;
			a[i][c - 1].push_back(d);
		}
		forn(j, 3) {
			sort(all(a[i][j]));
			reverse(all(a[i][j]));
			if (j > 0 && a[i][j].size() > 1) a[i][j].resize(1);
			if (a[i][j].size() > 3) a[i][j].resize(3);
		}
		solve(i);
	}
	for (int i = n - 1; i >= 0; --i)
		forn(j, 10) {
		uax(dp[i][j], dp[i + 1][j]);
		int sum = 1;
		if (a[i][0].size() > 1) sum = (int)a[i][0].size();
		else if (!a[i][0].empty() && !a[i][1].empty()) sum = 2;
		forn(k, sum) {
			int t = j + k + 1;
			if (t >= 10) uax(dp[i][j], dp[i + 1][t - 10] + b[i][k][1]);
			else uax(dp[i][j], dp[i + 1][t] + b[i][k][0]);
		}
	}
	cout << dp[0][0];
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}