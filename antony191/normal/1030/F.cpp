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

const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<typename T> bool uax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream & out = cout) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cout) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

ll gcd(ll a, ll b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int cnt(ll a) {
	int ans = 0;
	while (a > 0) {
		if (a & 1)
			ans++;
		a >>= 1;
	}
	return ans;
}

vector<ll> a, c, t, t1;

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		t1[v] = a[tl] * 1ll * c[tl] % mod;
	}
	else {
		int m = (tl + tr) >> 1;
		build(v + v, tl, m);
		build(v + v + 1, m + 1, tr);
		t[v] = t[v + v] + t[v + v + 1];
		t1[v] = t1[v + v] + (t1[v + v + 1] - (t[v + v + 1] % mod) * (m - tl + 1));
		t1[v] %= mod;
	}
}

void update(int v, int tl, int tr, int pos, int x) {
	if (tl == tr) {
		t[v] = x * 1ll;
		t1[v] = x * 1ll * c[tl] % mod;
	}
	else {
		int m = (tl + tr) >> 1;
		if (pos <= m)
			update(v + v, tl, m, pos, x);
		else
			update(v + v + 1, m + 1, tr, pos, x);
		t[v] = t[v + v] + t[v + v + 1];
		t1[v] = t1[v + v] + (t1[v + v + 1] - (t[v + v + 1] % mod) * (m - tl + 1));
		t1[v] %= mod;
	}
}

ll sum(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && tr == r)
		return t[v];
	int m = (tl + tr) >> 1;
	return sum(v + v, tl, m, l, min(m, r)) +
		sum(v + v + 1, m + 1, tr, max(m + 1, l), r);
}

ll sum1(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && tr == r)
		return t1[v];
	int m = (tl + tr) >> 1;
	ll a1 = sum1(v + v, tl, m, l, min(m, r));
	ll a2 = sum1(v + v + 1, m + 1, tr, max(m + 1, l), r);
	a1 += a2 - (sum(v + v + 1, m + 1, tr, max(m + 1, l), r) % mod) * 
		(m + 1 - min(m + 1, l));
	a1 %= mod;
	return a1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	a.resize(n); c.resize(n);
	t.resize(n << 2); t1.resize(n << 2);
	forn(i, n) cin >> c[i];
	forn(i, n) cin >> a[i];
	build(1, 0, n - 1);
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			update(1, 0, n - 1, -1 - x, y);
			a[-1 - x] = y;
			continue;
		}
		x--; y--;
		int l = x - 1, r = y;
		ll sumall = sum(1, 0, n - 1, x, y);
		while (r - l > 1) {
			int m = (l + r) >> 1;
			ll suma = sum(1, 0, n - 1, x, m);
			if (suma < sumall - suma)
				l = m;
			else
				r = m;
		}
		l++;
		int lans = c[l] - (l - x);
		ll ans = sum1(1, 0, n - 1, x, l) - (sum(1, 0, n - 1, x, l) % mod) * lans;
		ans = 0 - ans;
		ans %= mod;
		ans += sum1(1, 0, n - 1, l + 1, y) - (sum(1, 0, n - 1, l + 1, y) % mod) * (lans + (l - x + 1));
		ans = (ans % mod + mod) % mod;
		cout << ans << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}