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
ll gcd(ll a, ll b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<pair<int, int>> c(n, { -1, 1 }), del(n);
	forn(i, n) cin >> a[i];
	forn(i, n) {
		ll l = (ll)(pow(a[i] + 0.0, 1./3.) + 0.5);
		if (l * l * l == a[i]) {
			c[i] = { l, 3 };
			continue;
		}
		l = (ll)(pow(a[i] + 0.0, 0.25) + 0.5);
		if (l * l * l * l == a[i]) {
			c[i] = { l, 4 };
			continue;
		}
		l = (ll)(pow(a[i] + 0.0, 0.5) + 0.5);
		if (l * l == a[i])
			c[i] = { l, 2 };
	}
	vector<ll> b(n, -1ll);
	forn(i, n) {
		if (c[i].first > 0) continue;
		forn(j, n)
			if (a[j] != a[i] && gcd(a[i], a[j]) > 1) {
				b[i] = gcd(a[i], a[j]);
				break;
			}
	}
	vector<pair<ll, int>> ans;
	vector<bool> ans1(n + n + n, 0);
	forn(i, n) {
		if (c[i].first == -1) continue;
		forn(j, ans.size())
			if (gcd(ans[j].first, a[i]) > 1) {
				ans[j].second += c[i].second;
				if (c[i].first > 0) {
					a[i] = 1;
					break;
				}
				a[i] /= ans[j].first;
			}
		if (a[i] > 1)
			ans.push_back(c[i]);
	}
	forn(i, n) {
		if (b[i] == -1) continue;
		auto tmp = b[i];
		forn(j, ans.size()) {
			if (gcd(ans[j].first, tmp) > 1) {
				ans[j].second++;
				tmp = 1;
				break;
			}
		}
		if (tmp > 1) ans.push_back({ tmp, 1 });
		tmp = a[i] / b[i];
		forn(j, ans.size()) {
			if (gcd(ans[j].first, tmp) > 1) {
				ans[j].second++;
				tmp = 1;
				break;
			}
		}
		if (tmp > 1) ans.push_back({ tmp, 1 });
	}
	forn(i, n) {
		if (c[i].first > 0 || b[i] > 0) continue;
		forn(j, ans.size()) {
			if (ans[j].first == a[i]) {
				ans[j].second++;
				a[i] = 1;
			}
		}
		if (a[i] > 1) {
			ans.push_back({ a[i], 1 });
			ans1[(int)ans.size() - 1] = 1;
		}
	}
	ll as = 1;
	forn(i, ans.size()) {
		if (ans1[i])
			as = (as * (ans[i].second + 1) % mod) * (ans[i].second + 1) % mod;
		else
			as = as * (ans[i].second + 1) % mod;
	}
	as = (as % mod + mod) % mod;
	cout << as;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}