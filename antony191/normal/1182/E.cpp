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
ll a[3][3], b[3][3], c[3][3], d[3][3], tmp[3][3], res[3][3], e[3][3];
void mult(ll a[3][3], ll b[3][3]) {
	forn(i, 3) forn(j, 3) {
		tmp[i][j] = 0;
		forn(s, 3)
			tmp[i][j] = (tmp[i][j] + a[i][s] * b[s][j]) % (mod - 1);
	}
	forn(i, 3) forn(j, 3) a[i][j] = tmp[i][j];
}
void fastmat(int n) {
	forn(i, 3) res[i][i] = 1;
	while (n) {
		if (n & 1)
			mult(res, a);
		mult(a, a);
		n >>= 1;
	}
}
int fast(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}
	if (res < 0) res += mod;
	return res;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, f1, f2, f3, cc;
	cin >> n >> f1 >> f2 >> f3 >> cc;
	a[1][0] = a[2][1] = a[0][2] = a[1][2] = a[2][2] = 1;
	fastmat(n - 3);
	b[0][0] = 1;
	mult(b, res);
	ll ans = 1;
	ans = ans * 1ll * fast(f1, b[0][2]) % mod;
	c[0][1] = 1;
	mult(c, res);
	ans = ans * 1ll * fast(f2, c[0][2]) % mod;
	d[0][2] = 1;
	mult(d, res);
	ans = ans * 1ll * fast(f3, d[0][2]) % mod;
	e[0][0] = 1; e[0][1] = 2; e[0][2] = 3;
	mult(e, res);
	e[0][2] = (e[0][2] - n) % (mod - 1);
	if (e[0][2] < 0) e[0][2] += mod - 1;
	ans = ans * 1ll * fast(cc, e[0][2]) % mod;
	ans = (ans % mod + mod) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}