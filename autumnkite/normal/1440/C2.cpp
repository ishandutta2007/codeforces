#include <bits/stdc++.h>

const int N = 105;

int n, m;
char a[N][N];

struct Node {
	int ax, ay, bx, by, cx, cy;
};

void work(int i, int j, int mask) {
	for (int x = 0; x < 2; ++x) {
		for (int y = 0; y < 2; ++y) {
			if (mask >> (x << 1 | y) & 1) {
				a[i][j] ^= 1, a[i][j + 1] ^= 1, a[i + 1][j] ^= 1, a[i + 1][j + 1] ^= 1;
				a[i + x][j + y] ^= 1;
			}
		}
	}
}

void solve() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<Node> ans;
	if ((n & 1) && (m & 1) && a[n - 1][m - 1] == '1') {
		ans.push_back({n - 1, m - 1, n - 2, m - 1, n - 1, m - 2});
		a[n - 1][m - 1] = '0';
		a[n - 2][m - 1] ^= 1;
		a[n - 1][m - 2] ^= 1;
	}
	if (m & 1) {
		for (int i = 0; i < n - 1; i += 2) {
			if (a[i][m - 1] == '1' && a[i + 1][m - 1] == '1') {
				ans.push_back({i, m - 2, i, m - 1, i + 1, m - 1});
				a[i][m - 2] ^= 1;
			} else if (a[i][m - 1] == '1') {
				ans.push_back({i, m - 2, i + 1, m - 2, i + 1, m - 1});
				ans.push_back({i, m - 2, i, m - 1, i + 1, m - 1});
				a[i + 1][m - 2] ^= 1;
			} else if (a[i + 1][m - 1] == '1') {
				ans.push_back({i, m - 2, i + 1, m - 2, i, m - 1});
				ans.push_back({i, m - 2, i, m - 1, i + 1, m - 1});
				a[i + 1][m - 2] ^= 1;
			}
		}
		--m;
	}
	if (n & 1) {
		for (int i = 0; i < m - 1; i += 2) {
			if (a[n - 1][i] == '1' && a[n - 1][i + 1] == '1') {
				ans.push_back({n - 2, i, n - 1, i, n - 1, i + 1});
				a[n - 2][i] ^= 1;
			} else if (a[n - 1][i] == '1') {
				ans.push_back({n - 2, i, n - 2, i + 1, n - 1, i + 1});
				ans.push_back({n - 2, i, n - 1, i, n - 1, i + 1});
				a[n - 2][i + 1] ^= 1;
			} else if (a[n - 1][i + 1] == '1') {
				ans.push_back({n - 2, i, n - 2, i + 1, n - 1, i});
				ans.push_back({n - 2, i, n - 1, i, n - 1, i + 1});
				a[n - 2][i + 1] ^= 1;
			}
		}
		--n;
	}
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			for (int k = 0; k < 16; ++k) {
				work(i, j, k);
				if (a[i][j] == '0' && a[i][j + 1] == '0' && a[i + 1][j] == '0' && a[i + 1][j + 1] == '0') {
					for (int x = 0; x < 2; ++x) {
						for (int y = 0; y < 2; ++y) {
							if (k >> (x << 1 | y) & 1) {
								std::vector<int> p;
								for (int dx = 0; dx < 2; ++dx) {
									for (int dy = 0; dy < 2; ++dy) {
										if (x != dx || y != dy) {
											p.push_back(i + dx);
											p.push_back(j + dy);
										}
									}
								}
								ans.push_back({p[0], p[1], p[2], p[3], p[4], p[5]});
							}
						}
					}
					break;
				}
				work(i, j, k);
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (auto v : ans) {
		std::cout << v.ax + 1 << " " << v.ay + 1 << " ";
		std::cout << v.bx + 1 << " " << v.by + 1 << " ";
		std::cout << v.cx + 1 << " " << v.cy + 1 << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}