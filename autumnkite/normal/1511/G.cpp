#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	int LG = 0;
	while ((1 << LG) <= m) {
		++LG;
	}
	std::vector<std::vector<int>> v(LG, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		v[0][x] ^= 1;
	}

	for (int i = 1; i < LG; ++i) {
		for (int j = 0; j + (1 << i) <= m; ++j) {
			v[i][j] = v[i - 1][j] ^ v[i - 1][j + (1 << (i - 1))];
			if (v[i - 1][j + (1 << (i - 1))] & 1) {
				v[i][j] ^= 1 << i;
			}
		}
	}

	int q;
	std::cin >> q;
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		--l;
		int now = l;
		int res = 0;
		for (int i = LG - 1; i >= 0; --i) {
			if (now + (1 << i) <= r) {
				res ^= v[i][now];
				now += 1 << i;
			}
		}
		int odd = res & 1;
		res >>= 1;
		now = l;
		for (int i = LG - 1; i >= 0; --i) {
			if (now + (1 << i) <= r) {
				odd ^= v[i][now] & 1;
				res ^= odd << i;
				now += 1 << i;
			}
		}
		std::cout << (res ? 'A' : 'B');
	}
	std::cout << "\n";
}