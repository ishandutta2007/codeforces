#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	long long W;
	std::cin >> W;
	const int L = 3 * 5 * 7 * 8;
	std::bitset<16 * L> f;
	f[0] = 1;
	long long cnt = 0;
	for (int w = 1; w <= 8; ++w) {
		long long c;
		std::cin >> c;
		int nc = c < L / w ? c : c % (L / w) + L / w;
		cnt += (c - nc) / (L / w);
		for (int i = 0; (1 << i) <= nc; ++i) {
			f |= f << (w << i);
			nc -= 1 << i;
		}
		f |= f << (nc * w);
	}
	long long ans = 0;
	for (int i = 0; i < 16 * L && i <= W; ++i) {
		if (f[i]) {
			ans = std::max(ans, i + std::min((W - i) / L, cnt) * L);
		}
	}
	std::cout << ans << "\n";
}