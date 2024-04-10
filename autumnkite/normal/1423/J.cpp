#include <bits/stdc++.h>

const int LG = 60;
const int P = 1000000007;

void solve() {
	long long x;
	std::cin >> x;
	long long f[8];
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = LG - 1; i >= 0; --i) {
		if (x >> i & 1) {
			long long g2 = f[4] - f[0], g4 = f[5] - f[1], g6 = f[6] - f[2];
			f[0] = f[1] = f[0] + f[1] + f[2] + f[3];
			f[2] = f[3] = f[0] + g2;
			f[4] = f[5] = f[2] + g4;
			f[6] = f[7] = f[4] + g6;
		} else {
			long long g1 = f[4] - f[0], g3 = f[5] - f[1], g5 = f[6] - f[2], g7 = f[7] - f[3];
			f[0] = f[0] + f[1] + f[2] + f[3];
			f[1] = f[2] = f[0] + g1;
			f[3] = f[4] = f[1] + g3;
			f[5] = f[6] = f[3] + g5;
			f[7] = f[5] + g7;
		}
		if (!(i & 15)) {
			for (int j = 0; j < 8; ++j) {
				f[j] %= P;
			}
		}
	}
	std::cout << (f[0] % P + P) % P << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}