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

	int T;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			std::string tmp;
			std::cin >> tmp;
			for (int j = 0; j < m; ++j) {
				cnt += tmp[j] == '#';
			}
		}
		int ans = qpow(2, cnt);
		if (cnt == n * m) {
			--ans;
		}
		std::cout << ans << "\n";
	}
}