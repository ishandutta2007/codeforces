//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, mod = 998244353;
ll sum[maxn];
ll sums[maxn];
int v[maxn];

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int n;

int go(int l, int r, ll s) {
	if (l > r) {
		return 0;
	}
	ll cur = sums[r] - (l == 0 ? 0 : sums[l - 1]);
	if (cur + s <= 0) {
		return 0;
	}

	int lm = 0;
	int rm = (r - l) / 2;

	while (lm != rm) {
		int m = (lm + rm + 1) >> 1;

		int pos = l + 1 + (m - 1) * 2;
		ll mins = sum[pos];
		if (l + 1 >= 2) {
			mins -= sum[l - 1];
		}

		if (cur + s - 2 * mins > 0) {
			lm = m;
		}
		else {
			rm = m - 1;
		}
	}

	return lm + 1;
}

int go(int pos, ll s) {
	if (pos == n) {
		return 0;
	}

	return add(go(pos, n - 1, s), go(pos, n - 2, s - v[n - 1]));
}

bool cor(int mask) {
	vector <int> a, b;
	for (int i = 0; i < n; i++) {
		if ((mask >> i) & 1) {
			a.push_back(i);
		}
		else {
			b.push_back(i);
		}
	}

	for (int i = 1; i < (int)a.size() - 1; i++) {
		if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
			return false;
		}
	}

	for (int i = 1; i < (int)b.size() - 1; i++) {
		if (b[i] - b[i - 1] > b[i + 1] - b[i]) {
			return false;
		}
	}

	return true;
}

int stup() {
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll s = 0;

		if (!cor(mask)) {
			continue;
		}

		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				s += v[i];
			}
			else {
				s -= v[i];
			}
		}

		if (s > 0) {
			ans++;
		}
	}

	return ans;
}

mt19937 rr;

int main() {
	bool read = true;
	int t;
	if (read) {
		cin >> t;
	}
	else {
		t = (int)1e4;
	}
	while (t--) {
		if (read) {
			scanf("%d", &n);
		}
		else {
			n = rr() % 10 + 1;
		}
		for (int i = 0; i < n; i++) {
			if (read) {
				scanf("%d", &v[i]);
			}
			else {
				v[i] = rr() % 10 + 1;
			}

			if (i) {
				sums[i] = sums[i - 1];
			}

			sums[i] += v[i];

			if (i >= 2) {
				sum[i] = sum[i - 2];
			}
			else {
				sum[i] = 0;
			}

			sum[i] += v[i];
		}

		int ans = 0;
		ll s = 0;

		for (int i = 0; i < n; i++) {
			s -= v[i];
			ans = add(ans, go(i + 1, s));
		}

		s = v[0];
		for (int i = 1; i < n; i++) {
			s -= v[i];
			ans = add(ans, go(i + 1, s));
		}

		s = 0;
		for (int i = 0; i < n; i++) {
			s += v[i];
		}

		ans = add(ans, 1);
		for (int i = n - 1; i >= 0; i--) {
			s -= 2 * v[i];
			if (s > 0) {
				ans = add(ans, 1);
			}
		}

		printf("%d\n", ans);
		//assert(ans == stup());
	}
}