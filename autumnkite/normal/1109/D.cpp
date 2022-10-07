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

	int n, m;
	std::cin >> n >> m;
	int Cm = 1, Cn = 1, ans = 0;
	for (int i = 1; i < n && i <= m; ++i) {
		ans = (ans + 1ll * Cn * Cm % P * qpow(1ll * m * n % P, n - 1 - i) % P * (i + 1)) % P;
		Cm = 1ll * Cm * (m - i) % P * qpow(i, P - 2) % P;
		Cn = 1ll * Cn * (n - 1 - i) % P;
	}
	std::cout << 1ll * ans * qpow(n, P - 2) % P << "\n";
}