#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int qpow(int a, int p) {
	if (p == 0)
		return 1;
	else if (p % 2 == 1)
		return (a * qpow(a, p - 1)) % mod;
	else {
		int h = qpow(a, p / 2);
		return (h * h) % mod;
	}
}

int inv(int a) {
	return qpow(a, mod - 2);
}

vector<int> f(100100);
vector<int> inv_f(100100);

int C(int n, int k) {
	return (((f[n] * inv_f[n - k]) % mod) * inv_f[k]) % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f[0] = 1;
	inv_f[0] = 1;
	for (int i = 1; i < 100100; ++i) {
		f[i] = (i * f[i - 1]) % mod;
		inv_f[i] = inv(f[i]);
	}

	int n;
	cin >> n;
	int LB = 0, LW = 0, LQ = 0;
	int RB = 0, RW = 0, RQ = 0;

	int DB = 0;
	int DW = 0;
	int D = 0;

	bool care_doubles = true;

	for (int i = 0; i < n; ++i) {
		char c1, c2;

		char c;
		cin >> c;
		if (c == 'B')
			LB++;
		if (c == 'W')
			LW++;
		if (c == '?')
			LQ++;
		c1 = c;

		cin >> c;
		if (c == 'B')
			RB++;
		if (c == 'W')
			RW++;
		if (c == '?')
			RQ++;
		c2 = c;

		if (c2 == 'B')
			c2 = 'W';
		else if (c2 == 'W')
			c2 = 'B';

		bool has_B = (c1 == 'B' || c2 == 'B');
		bool has_W = (c1 == 'W' || c2 == 'W');

		if (has_B && has_W)
			care_doubles = false;
		else if (has_B && !has_W)
			DB++;
		else if (!has_B && has_W)
			DW++;
		else if (!has_B && !has_W)
			D++;
	}

	int ans = 0;
	swap(RB, RW);
	for (int i = max(LB, RB); n - i >= max(LW, RW); ++i) {
		ans = (ans + (C(LQ, i - LB) * C(RQ, i - RB)) % mod) %mod;
	}

	if (n > 1 && ((DB >= 1 && DW >= 1) || D >= 1) && care_doubles) {
		for (int i = max((int)1, DB); n - i >= max((int)1, DW); ++i) {
			ans = (ans - C(D, i - DB) + mod) %mod;
		}
	}

	cout << ans << endl;

	return 0;
}