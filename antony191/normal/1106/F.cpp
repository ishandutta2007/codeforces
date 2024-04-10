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
ll a[100][100], b[100][100], res[100][100], tmp[100][100];
int k, n, m;
void mult(ll a[100][100], ll b[100][100]) {
	forn(i, k) forn(j, k) {
		tmp[i][j] = 0;
		forn(s, k)
			tmp[i][j] = (tmp[i][j] + a[i][s] * b[s][j]) % md;
	}
	forn(i, k) forn(j, k) a[i][j] = tmp[i][j];
}
int fastmat() {
	forn(i, k) res[i][i] = 1;
	while (n) {
		if (n & 1)
			mult(res, b);
		mult(b, b);
		n >>= 1;
	}
	a[0][k - 1] = 1;
	mult(a, res);
	return a[0][k - 1];
}
int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
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
int fastmd(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % md;
		a = a * 1ll * a % md;
		n >>= 1;
	}
	if (res < 0) res += md;
	return res;
}
ll gcdex(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcdex(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	forn(i, k) {
		cin >> b[k - 1 - i][k - 1];
	}
	forn(i, k - 1) b[i + 1][i] = 1;
	cin >> n >> m;
	n -= k;
	ll t = fastmat();
	t = (t % md + md) % md;
	int nn = sqrt(mod);
	set<pair<int, int>> ans;
	for (int i = 0; i < md + nn; i += nn) {
		ans.insert({ fast(3, i), i });
	}
	int q = m, st = -1;
	for (int i = 0; i < nn; ++i) {
		auto j = ans.lower_bound({ q, 0 });
		if (j != ans.end() && j->x == q) {
			st = j->y - i;
			break;
		}
		q = (q * 3ll) % mod;
		if (q < 0) q += mod;
	}
	auto tmp = gcd(t, st);
	tmp = abs(tmp);
	if (tmp) {
		t /= tmp; st /= tmp;
	}
	bool ok = 1;
	while (int tmp = gcd(t, md)) {
		if (t == st && t == 0) break;
		if (tmp <= 1) break;
		if (st % tmp) {
			ok = 0;
			break;
		}
		st /= tmp;
		t /= tmp;
	}
	if (!ok) cout << -1 << el;
	else {
		ll x, y;
		gcdex(t, md, x, y);
		x %= md;
		x = x * st % md;
		if (x < 0) x += md;
		cout << fast(3, x) << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}