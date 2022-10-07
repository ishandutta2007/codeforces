#include <bits/stdc++.h>

const int N = 55;

int n, m;
int a[N][N], b[N][N];

bool check(int a[N][N]) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i < n && a[i][j] >= a[i + 1][j]) {
				return false;
			}
			if (j < m && a[i][j] >= a[i][j + 1]) {
				return false;
			}
		}
	}
	return true;
}

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
			std::cin >> b[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int t1 = std::min(a[i][j], b[i][j]), t2 = std::max(a[i][j], b[i][j]);
			a[i][j] = t1, b[i][j] = t2;
		}
	}

	if (check(a) && check(b)) {
		std::cout << "Possible\n";
	} else {
		std::cout << "Impossible\n";
	}
}