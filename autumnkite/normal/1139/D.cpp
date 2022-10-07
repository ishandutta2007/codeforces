#include <bits/stdc++.h>

const int P = 1000000007;

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
	int invn = qpow(n, P - 2);

	std::vector<int> mu(n + 1);
	mu[1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + i; j <= n; j += i) {
			mu[j] -= mu[i];
		}
	}

	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		int t = 1ll * (n / i) * invn % P;
		ans = (ans - 1ll * mu[i] * t * qpow(1 - t, P - 2)) % P;
	}
	std::cout << (ans + P) % P << "\n";
}