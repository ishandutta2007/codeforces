#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second;
	}
	long long ans[2] = {};
	for (int k = 0; k < n; ++k) {
		int cnt[4][4][4] = {};
		for (int i = 0; i < n; ++i) {
			if (i != k) {
				int x = (a[i].first + 4 - a[k].first) & 3;
				int y = (a[i].second + 4 - a[k].second) & 3;
				int b = std::__gcd(abs(a[i].first - a[k].first), abs(a[i].second - a[k].second)) & 3;
				++cnt[x][y][b];
			}
		}
		for (int ix = 0; ix < 4; ++ix) {
			for (int iy = 0; iy < 4; ++iy) {
				for (int ib = 0; ib < 4; ++ib) {
					for (int jx = 0; jx < 4; ++jx) {
						for (int jy = 0; jy < 4; ++jy) {
							for (int jb = 0; jb < 4; ++jb) {
								int S = (ix * jy - iy * jx + 16) & 3;
								if (S & 1 || (ib & 1) != (jb & 1)) {
									continue;
								}
								int dx = (ix + 4 - jx) & 3, dy = (iy + 4 - jy) & 3;
								int kb = std::__gcd(dx, dy);
								if (((ib + jb + kb) >> 1 & 1) == (S >> 1 & 1)) {
									ans[ib & 1] += 1ll * cnt[ix][iy][ib] * cnt[jx][jy][jb];
									if (ix == jx && iy == jy && ib == jb) {
										ans[ib & 1] -= cnt[ix][iy][ib];
									}
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout << ans[0] / 6 + ans[1] / 2 << "\n";
}