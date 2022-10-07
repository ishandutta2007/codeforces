#include <bits/stdc++.h>

const int P = 998244353;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
	}
	std::sort(a.begin(), a.end());

	std::vector<long long> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + a[i];
	}
	for (int k = 1; k <= n; ++k) {
		long long ans = 0;
		for (int i = n - k; i >= 0; i -= k) {
			ans += sum[i];
		}
		std::cout << 1ll * ans % P * qpow(n, P - 2) % P << " \n"[k == n];
	}
}