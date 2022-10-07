#include <bits/stdc++.h>

const int N = 105;

int n, m;
int a[N][N];

void solve() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << a[i][j] + ((i + j + a[i][j] + a[0][0]) & 1) << " ";
		}
		std::cout << "\n";
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