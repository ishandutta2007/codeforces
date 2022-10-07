#include <bits/stdc++.h>

int W, H, K;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> W >> H >> K;
	int ans = 0;
	for (int i = 1; i <= 4 * K; i += 4) {
		ans += (H - i + W - i) * 2;
	}
	std::cout << ans << "\n";
}