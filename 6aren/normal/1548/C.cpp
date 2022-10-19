#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007LL

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> a(3 * n + 3), b = vector<int>({3, 3, 1});
	vector<int> fac(3 * n + 4, 1), ifac(3 * n + 4, 1);
	for (int i = 1; i < 3 * n + 4; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	auto power = [](int x, int y) {
		int res = 1;
		while (y) {
			if (y % 2) res = res * x % MOD;
			y >>= 1;
			x = x * x % MOD;
		}
		return res;
	};
	ifac[3 * n + 3] = power(fac[3 * n + 3], MOD - 2); 
	for (int i = 3 * n + 2; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	auto C = [&fac, &ifac](int n, int k) {
		return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
	};

	for (int i = 1; i <= 3 * n + 3; i++) {
		a[i - 1] = C(3 * n + 3, i);
	}

	const int INV3 = power(3, MOD - 2);

	auto poly_div = [INV3](vector<int> a, vector<int> b) {
		vector<int> res(a.size() - b.size() + 1);
		for (int i = 0; i < (int) a.size() - (int) b.size() + 1; i++) {
			res[i] = a[i] * INV3 % MOD;
			for (int j = 0; j < (int) b.size(); j++) {
				a[i + j] = (a[i + j] - res[i] * b[j] % MOD + MOD) % MOD;
			}
		}
		return res;
	};

	vector<int> res = poly_div(a, b);

	while (q--) {
		int x;
		cin >> x;
		cout << res[x] << '\n';
	}

	return 0;
}