#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n;
	std::cin >> m;
	int seed, base;
	auto rnd = [&]() {
		int res = seed;
		seed = (1ll * seed * base + 233) % P;
		return res;
	};
	std::vector<int> a(n), t(n), b(n);
	long long sum[2] = {0, 0};
	int lst = 0;
	for (int k = 0; k < m; ++k) {
		int p, lim;
		std::cin >> p >> lim >> seed >> base;
		for (int i = lst; i < p; ++i) {
			t[i] = rnd() % 2;
			a[i] = rnd() % lim + 1;
			b[i] = a[i];
			sum[t[i]] += a[i];
		}
		lst = p;
	}

	int A;
	if (sum[t[0]] > sum[t[0] ^ 1]) {
		--a[0];
		A = t[0] ^ 1;
	} else {
		A = t[0];
	}
	long long cnt = 0;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			if (t[i] == A) {
				cnt += a[i];
				a[i] = 0;
			} else {
				int t = std::min<long long>(a[i], cnt);
				cnt -= t;
				a[i] -= t;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		long long t = (b[i] - a[i]) ^ (1ll * (i + 1) * (i + 1));
		t = (t + 1) % P;
		ans = 1ll * ans * t % P;
	}
	std::cout << ans << "\n";
}