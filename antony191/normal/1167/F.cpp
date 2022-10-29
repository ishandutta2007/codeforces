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
const ll llinf = 3e18, mod = 1000'000'007, maxn = 1e5;
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

vector<ll> f, a, b;
void upd(int pos, int a) {
	for (int i = pos; i < (int)f.size(); i = (i | (i + 1)))
		f[i] += a;
}
ll sum(int r) {
	ll ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) ans += f[r];
	return ans;
}
ll gett(int n) {
	f.assign(n, 0);
	ll ans = 0;
	forn(i, n) {
		ll tmp = sum(a[i]) % mod;
		tmp = tmp * b[i] % mod;
		tmp = tmp * 1ll * (n - i) % mod;
		ans = (ans + tmp) % mod;
		upd(a[i], i + 1);
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	vector<pair<ll, int>> a1(n);
	forn(i, n) {
		cin >> a1[i].x;
		b[i] = a1[i].x;
		a1[i].y = i;
	}
	sort(all(a1));
	forn(i, n) a[a1[i].y] = i;
	ll ans = gett(n);
	reverse(all(a)); reverse(all(b));
	ans += gett(n);
	forn(i, n) {
		ll tmp = b[i] * 1ll * (i + 1) % mod * 1ll * (n - i) % mod;
		ans = (ans + tmp) % mod;
	}
	ans = (ans % mod + mod) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}