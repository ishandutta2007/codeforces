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

const int inf = 1e9;
const ll llinf = 1e18, mod = 998244353;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define int long long

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

ll dp[19][10][1024], cnt[19][10][1024];

vector<ll> st(19, 1);
int qq;

ll solve(ll r) {
	if (!r) return 0ll;
	ll ans = 0ll;
	vector<int> rr;
	while (r > 0) {
		rr.push_back(r % 10);
		r /= 10;
	}
	reverse(all(rr));
	vector<bool> t(10), p(10);
	ll cur = 0ll;
	ll e = 1ll;
	forn(i, (int)rr.size() - 1) e *= 10ll;
	e--;
	ans = solve(e);
	forn(i, rr.size()) {
		forn(j, rr[i]) {
			if (i == 0 && j == 0) continue;
			forn(mask, 1024) {
				int c = 0;
				forn(k, 10) {
					t[k] = (mask & (1 << k));
					c += t[k] | p[k];
				}
				if (c > qq)
					continue;
				ans = (ans + dp[(int)rr.size() - i][j][mask]) % mod;
				ans = (ans + cur * 1ll * cnt[(int)rr.size() - i][j][mask]) % mod;
			}
		}
		p[rr[i]] = 1;
		cur = (cur + (rr[i] * 1ll * st[(int)rr.size() - i - 1] % mod)) % mod;
	}
	int c = 0;
	forn(i, 10) c += p[i];
	if (c <= qq) {
		ans = (ans + cur) % mod;
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll l, r, k;
	cin >> l >> r >> k;
	qq = k;
	firn(i, 19) st[i] = st[i - 1] * 10ll % mod;
	forn(i, 10) {
		dp[1][i][1 << i] = i * 1ll;
		cnt[1][i][1 << i] = 1ll;
	}
	vector<bool> tmp(10);
	for (int i = 2; i < 19; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int mask = 0; mask < 1024; ++mask) {
				if ((mask & (1 << j)) == 0) continue;
				forn(r, 10) tmp[r] = mask & (1 << r);
				forn(r, 10)
					if (tmp[r]) {
						dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][r][mask]) % mod;
						dp[i][j][mask] = (dp[i][j][mask] + dp[i - 1][r][mask - (1 << j)]) % mod;
						cnt[i][j][mask] = ((cnt[i][j][mask] + cnt[i - 1][r][mask]) % mod + cnt[i - 1][r][mask - (1 << j)]) % mod;
					}
				dp[i][j][mask] = (dp[i][j][mask] + (cnt[i][j][mask] * 1ll * st[i - 1] % mod) * j) % mod;
			}
		}
	}
	ll ans = 0ll;
	if (r == (ll)(1e18)) {
		r--;
		if (k >= 2) ans = st[18];
	}
	ans += (solve(r) - solve(l - 1)) % mod;
	ans = (ans % mod + mod) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}