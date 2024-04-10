#include <bits/stdc++.h>

int n, m;
int a[505][505];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if ((i + j) & 1) {
				std::cout << 720720 - a[i][j] * a[i][j] * a[i][j] * a[i][j];
			} else {
				std::cout << 720720;
			}
			std::cout << " \n"[j == m];
		}
	}
}