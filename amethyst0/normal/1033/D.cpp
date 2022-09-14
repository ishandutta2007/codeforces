#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = 510, mod = 998244353;
ll v[maxn];

ll is_cube(ll x) {
	ll l = 1, r = (ll)2e6;

	ll inf = (ll)2e18 + 10;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		ll cur = m * m;

		if (cur >= inf / m) {
			cur = inf;
		}
		else {
			cur *= m;
		}

		if (cur > x) {
			r = m - 1;
		}
		else {
			l = m;
		}
	}

	if (l * l * l == x) {
		return l;
	}

	return -1;
}

ll is_qu(ll x) {
	ll l = 1, r = (ll)5e4;

	ll inf = (ll)2e18 + 10;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		ll cur = m * m;

		if (cur >= inf / cur) {
			cur = inf;
		}
		else {
			cur *= cur;
		}

		if (cur > x) {
			r = m - 1;
		}
		else {
			l = m;
		}
	}

	if (l * l * l * l == x) {
		return l;
	}

	return -1;
}

ll is_quad(ll x) {
	ll l = 1, r = (ll)2e9;

	ll inf = (ll)2e18 + 10;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		ll cur = m;

		if (cur >= inf / cur) {
			cur = inf;
		}
		else {
			cur *= cur;
		}

		if (cur > x) {
			r = m - 1;
		}
		else {
			l = m;
		}
	}

	if (l * l == x) {
		return l;
	}

	return -1;
}

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

bool dev[maxn];

int main() {
	vector <ll> g;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		ll x = is_cube(v[i]);

		if (x != -1) {
			g.push_back(x);
		}

		x = is_qu(v[i]);

		if (x != -1) {
			g.push_back(x);
		}

		x = is_quad(v[i]);

		if (x != -1) {
			g.push_back(x);
		}
	}

	sort(g.begin(), g.end());
	g.resize(unique(g.begin(), g.end()) - g.begin());

	ll ans = 1;

	for (int i = 0; i < (int)g.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			while (v[j] % g[i] == 0) {
				dev[j] = true;
				cnt++;
				v[j] /= g[i];
			}
		}

		ans *= (cnt + 1);
		ans %= mod;
	}

	g.clear();

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll x = v[i];
			ll y = v[j];

			ll gc = gcd(x, y);

			if (gc != 1 && gc != x && gc != y) {
				g.push_back(gc);
			}
		}
	}

	sort(g.begin(), g.end());
	g.resize(unique(g.begin(), g.end()) - g.begin());

	for (int i = 0; i < (int)g.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			while (v[j] % g[i] == 0) {
				dev[j] = true;
				cnt++;
				v[j] /= g[i];
			}
		}

		ans *= (cnt + 1);
		ans %= mod;
	}

	g.clear();

	vector <pair <ll, int> > f;

	for (int i = 0; i < n; i++) {
		if (v[i] != 1) {
			f.push_back(mp(v[i], i));
		}
	}

	sort(f.begin(), f.end());

	int pos = 0;

	while (pos < (int)f.size()) {
		int r = pos;

		while (r < (int)f.size() && f[pos].first == f[r].first) {
			r++;
		}

		if (dev[f[pos].second]) {
			ans *= (r - pos + 1);
			ans %= mod;
		}
		else {
			ans *= (r - pos + 1);
			ans %= mod;
			ans *= r - pos + 1;
			ans %= mod;
		}

		pos = r;
	}

	cout << ans << endl;

	//system("pause");
}