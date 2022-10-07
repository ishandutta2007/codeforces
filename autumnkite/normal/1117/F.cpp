#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	std::vector<std::vector<int>> a(m, std::vector<int>(m));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	
	std::vector<bool> can(1 << m, true);
	for (int x = 0; x < m; ++x) {
		for (int y = x; y < m; ++y) {
			if (!a[x][y]) {
				std::vector<bool> tmp(1 << m, true);
				int lst = -1;
				int now = 0;
				for (int i = 0; i < n; ++i) {
					if (s[i] == 'a' + x || s[i] == 'a' + y) {
						if (lst != -1 && (x == y || s[i] != s[lst])) {
							tmp[now] = false;
						}
						lst = i;
						now = 0;
					} else {
						now |= 1 << (s[i] - 'a');
					}
				}
				for (int i = 0; i < m; ++i) {
					for (int S = 0; S < (1 << m); ++S) {
						if (S >> i & 1) {
							tmp[S] = tmp[S] & tmp[S ^ (1 << i)];
						}
					}
				}
				for (int S = 0; S < (1 << m); ++S) {
					if (!(S >> x & 1) && !(S >> y & 1)) {
						can[S] = can[S] & tmp[S];
					}
				}
			}
		}
	}

	for (int S = 1; S < (1 << m); ++S) {
		if (can[S]) {
			can[S] = false;
			for (int i = 0; i < m; ++i) {
				if (S >> i & 1 && can[S ^ (1 << i)]) {
					can[S] = true;
					break;
				}
			}
		}
	}
	std::vector<int> cnt(1 << m);
	for (int i = 0; i < n; ++i) {
		++cnt[1 << (s[i] - 'a')];
	}
	for (int S = 1; S < (1 << m); ++S) {
		cnt[S] = cnt[S & (S - 1)] + cnt[S & -S];
	}
	int ans = 0;
	for (int S = 0; S < (1 << m); ++S) {
		if (can[S]) {
			ans = std::max(ans, cnt[S]);
		}
	}
	std::cout << n - ans << "\n";
}