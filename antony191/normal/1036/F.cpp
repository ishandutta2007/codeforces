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
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define int long long
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

template<class iterator> void output(iterator begin, iterator end, ostream & out = cerr) {
	while (begin != end) {
		out << (*begin) << ' ';
		begin++;
	}
	out << '\n';
}

template<class T> void output(T x, ostream & out = cerr) {
	output(all(x), out);
}

mt19937 rnd(time(NULL));

int un[60];
vector<ll> st[60];
void pre_calc() {
	for (int i = 2; i < 60; ++i) {
		int tmp = 0;
		for (int j = 2; j < i; ++j)
			if (i % j == 0)
				tmp += un[j];
		un[i] = 1 - tmp;
	}
	for (int i = 18; i < 60; ++i) {
		bool bad = 0;
		for (int j = 2; j <= 10 && !bad; ++j) {
			bad = 0;
			ll t = 1ll;
			for (int r = 0; r < i; ++r) {
				ll tmp = t * 1ll * j;
				if (tmp / j != t) {
					bad = 1;
					break;
				}
				t = tmp;
			}
			if (bad) break;
			st[i].push_back(t);
		}
	}
}

ll ans(ll n) {
	ll a = 0;
	for (int i = 2; i < 18; ++i) {
		ll k = (ll)pow(n + .0, 1. / i);
		ll tmp = 1ll;
		for (int j = 0; j < i; ++j) tmp *= k;
		if (tmp > n) k--;
		else {
			ll tmp = 1ll;
			bool er = 1;
			for (int j = 0; j < i; ++j) {
				ll r = tmp * (k + 1);
				if (r / (k + 1) != tmp) {
					er = 0;
					break;
				}
				tmp = r;
			}
			if (er && tmp <= n)
				k++;
		}
		k--;
		if (k == 0) break;
		a += k * un[i];
	}
	for (int i = 18; i < 60; ++i) {
		if (st[i][0] > n) break;
		forn(j, st[i].size()) {
			if (st[i][j] > n) {
				a += j * 1ll * un[i];
				break;
			}
		}
		if (st[i].back() <= n) {
			a += (int)st[i].size() * 1ll * un[i];
		}
	}
	return a;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre_calc();
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << n - 1 - ans(n) << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}