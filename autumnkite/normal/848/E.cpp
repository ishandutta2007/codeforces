#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	static const int r[16] = {
		0, 4, 8, -1, 16, -10, 4, -12, 
		-48, 26, -44, 15, -16, -4, -4, -1
	};
	static const int F[16] = {
		0, 0, 0, 24, 4, 240, 204, 1316, 
		2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404
	};

	std::vector<int> f(n + 1);
	for (int i = 0; i < 16 && i <= n; ++i) {
		f[i] = F[i];
	}
	for (int i = 16; i <= n; ++i) {
		f[i] = 0;
		for (int j = 0; j < 16; ++j) {
			f[i] = (f[i] + 1ll * r[j] * f[i - j - 1]) % P;
		}
	}
	std::cout << (f[n] + P) % P << "\n";
}