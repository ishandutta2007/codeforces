/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10, mod = 998244353;

vector <int> buf[maxn];
int posit;
ll root, root1, rootpw;

map <int, int> dp;
int k;

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (a * my_pow(a, b - 1)) % mod;
	}

	ll x = my_pow(a, b >> 1);

	return (x * x) % mod;
}

int revv(int x, int st) {
	int y = 0;

	for (int i = 0; i < st; i++) {
		y <<= 1;
		y += x & 1;
		x >>= 1;
	}

	return y;
}

void dft(vector <int> &a, int st, bool rev) {
	for (int i = 0; i < (int)a.size(); i++) {
		int pos = revv(i, st);

		if (pos > i) {
			swap(a[pos], a[i]);
		}
	}

	int n = (int)a.size();

	for (int len = 2; len <= n; len <<= 1) {
		ll wlen = (rev ? root1 : root);

		for (int j = len; j != rootpw; j <<= 1) {
			wlen = (wlen * wlen) % mod;
		}

		for (auto i = a.begin(); i != a.end(); i += len) {
			ll w = 1;
			for (auto j = i; j < i + len / 2; j++) {
				int u = *j, v = *(j + len / 2);
				v = (v * 1ll * w) % mod;

				(*j) = (u + v >= mod ? u + v - mod : u + v);

				(*(j + len / 2)) = (u - v < 0 ? u - v + mod : u - v);

				w = (w * wlen) % mod;
			}
		}
	}

	if (rev) {
		ll nrev = my_pow(n, mod - 2);

		for (int i = 0; i < n; i++) {
			a[i] = (a[i] * nrev) % mod;
		}
	}
}

vector <int> operator *(vector <int> a, vector <int> b) {
	int st = 1;
	int x = (int)a.size() + b.size() - 1;

	while ((1 << st) < max(a.size(), b.size())) {
		st++;
	}

	st++;

	a.resize(1 << st);
	b.resize(1 << st);

	dft(a, st, false);
	dft(b, st, false);

	for (int i = 0; i < (int)a.size(); i++) {
		a[i] = (a[i] * 1ll * b[i]) % mod;
	}

	dft(a, st, true);

	a.resize(x);

	return a;
}

vector <int> operator +(const vector <int> &a, const vector <int> &b) {
	vector <int> c(max(a.size(), b.size()));

	for (int i = 0; i < (int)c.size(); i++) {
		if (i < (int)a.size()) {
			c[i] += a[i];
		}

		if (i < (int)b.size()) {
			c[i] += b[i];

			if (c[i] >= mod) {
				c[i] -= mod;
			}
		}
	}

	return c;
}

int go(int n) {
	if (dp.count(n)) {
		return dp[n];
	}

	dp[n] = posit;
	int pos = posit++;

	if (n == 0) {
		buf[pos].push_back(1);
	} else if (n == 1) {
		buf[pos].push_back(1);
		buf[pos].push_back(1);
	} else if (n == 2) {
		buf[pos].push_back(1);
		buf[pos].push_back(3);
		buf[pos].push_back(1);
	} else if (n == 3) {
		buf[pos].push_back(1);
		buf[pos].push_back(5);
		buf[pos].push_back(5);
		buf[pos].push_back(1);
	} else if (n == 4) {
		buf[pos].push_back(1);
		buf[pos].push_back(7);
		buf[pos].push_back(13);
		buf[pos].push_back(7);
		buf[pos].push_back(1);
	} else {
		int a = n / 2;
		int b = n - a;

		buf[pos] = buf[go(a - 1)] * buf[go(b - 1)];

		buf[pos].push_back(0);

		for (int i = (int)buf[pos].size() - 2; i >= 0; i--) {
			swap(buf[pos][i], buf[pos][i + 1]);
		}

		buf[pos] = buf[pos] + buf[go(a)] * buf[go(b)];
	}

	if (buf[pos].size() > k + 1) {
		buf[pos].resize(k + 1);
	}

	return pos;
}

int main() {
	root = 44759;
	root1 = my_pow(44759, mod - 2);
	rootpw = 1 << 16;
	int n;

	cin >> n >> k;

	int pos = go(n);

	buf[pos].resize(k + 1);

	for (int i = 1; i <= k; i++) {
		printf("%d ", buf[pos][i]);
	}

	return 0;
}