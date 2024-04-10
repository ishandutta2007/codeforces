#include <bits/stdc++.h>

using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	const int N = 200005;
	const int MOD = 998244353;

	vector<int> fac(N), ifac(N);

	auto power = [&](int x, int y) {
		int res = 1;
		while (y) {
			if (y % 2) {
				res = 1LL * res * x % MOD;
			}
			y >>= 1;
			x = 1LL * x * x % MOD;
		}
		return res;
	};

	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	}
	ifac[N - 1] = power(fac[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) {
		ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
	}

	vector<int> cnt(N);

	vector<int> s(n + 1), t(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		cnt[s[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}

	int res = 0, cur = 1;
	for (int i = 1; i < N; i++) {
		cur = 1LL * cur * ifac[cnt[i]] % MOD;
	}

	vector<int> bit(N);

	auto update = [&](int k, int val) {
		for (int i = k; i < N; i += (i & (-i))) {
			bit[i] += val;
		}
	};

	auto get = [&](int k) {
		int res = 0;
		for (int i = k; i > 0; i -= (i & (-i))) {
			res += bit[i];
		}
		return res;
	};

	for (int i = 1; i < N; i++) {
		update(i, cnt[i]);
	}

	for (int i = 0; i <= min(n, m); i++) {
		if (i == min(n, m)) {
			if (n < m) {
				res = (res + 1) % MOD;
			}
			break;
		}
		// i previous are equal, choose any < t[i + 1]
		int foo = get(t[i + 1] - 1);
		res = (res + 1LL * cur * foo % MOD * fac[n - i - 1]) % MOD;
		// make a[i + 1] == t[i + 1];
		cur = 1LL * cur * cnt[t[i + 1]] % MOD;
		cnt[t[i + 1]]--;
		update(t[i + 1], - 1);
		if (cnt[t[i + 1]] < 0) break;
	}
	cout << res << '\n';
}