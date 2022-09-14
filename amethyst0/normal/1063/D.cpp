#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

ll solve(ll n, ll k, ll c, ll d, ll lm, ll rm) {
	if (d > k) {
		return -1;
	}

	ll px = rm;

	if (c != 0) {
		px = (k - d) / c - n;
	}

	if (px < lm) {
		return -1;
	}

	px = min(px, rm);

	if (k % (n + px) < d) {
		throw 1;
	}

	if (k % (n + px) <= d + min(d, px)) {
		return px;
	}

	return -1;
}

ll spec_solve(ll n, ll k, ll c, ll d, ll lm, ll rm) {
	if (d > k) {
		return -1;
	}

	if (k - 2 * d + 2 * n + 1 < 0) {
		return -1;
	}

	ll px = (k - 2 * d + 2 * n + 1) / (c + 1) - n;
	ll cc = px;

	if (px < lm) {
		return -1;
	}

	px = min(px, rm);

	if (k % (n + px) < d + d - n + px - 1) {
		throw 1;
	}

	if (k % (n + px) <= d + min(d, px)) {
		return px;
	}

	return -1;
}

ll presolve(ll n, ll k, ll c, ll d, ll lm, ll rm) {
	ll ans = -1;

	if (rm > n - d) {
		if (lm <= n - d) {
			ans = solve(n, k, c, d, lm, n - d);
		}

		ans = max(ans, spec_solve(n, k, c, d, max(lm, n - d + 1), rm));
	}
	else {
		ans = solve(n, k, c, d, lm, rm);
	}

	return ans;
}

int main() {
	ll n, k, l, r;

	cin >> n >> l >> r >> k;

	if (r < l) {
		r += n;
	}

	ll d = r - l + 1;

	if (d == n) {
		d = 0;
	}

	ll ans = -1;

	for (int x = 0; x <= (int)1e6; x++) {
		if (x > n) {
			break;
		}
		ans = max(ans, presolve(n, k, k / (n + x), d, x, x));
	}

	for (int c = 0; c <= (int)1e6; c++) {
		if (c > n) {
			break;
		}
		ll lm = (k + 1 + c) / (c + 1) - n;
		if (lm < 0) {
			lm = 0;
		}

		ll rm = n;

		if (c != 0) {
			rm = k / c - n;
		}

		rm = min(rm, n);

		if (lm > rm) {
			continue;
		}

		ans = max(ans, presolve(n, k, c, d, lm, rm));

		if (c == 1 && d == 0) {
			ans = max(ans, presolve(n, k, c, d, lm, rm) + 1);
		}
	}

	cout << ans << endl;

	//system("pause");
}