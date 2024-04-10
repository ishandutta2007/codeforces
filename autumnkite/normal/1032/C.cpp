#include <bits/stdc++.h>

const int N = 100005;

int n, a[N];
bool f[N][5];
int g[N][5];

void getAns(int k, int x) {
	if (k == 1) {
		std::cout << x + 1 << " ";
		return;
	}
	getAns(k - 1, g[k][x]);
	std::cout << x + 1 << " ";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}

	for (int i = 0; i < 5; ++i) {
		f[1][i] = true;
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1]) {
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					if (j != k && f[i - 1][k]) {
						f[i][j] = 1;
						g[i][j] = k;
					}
				}
			}
		}
		if (a[i] > a[i - 1]) {
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					if (j > k && f[i - 1][k]) {
						f[i][j] = 1;
						g[i][j] = k;
					}
				}
			}
		}
		if (a[i] < a[i - 1]) {
			for (int j = 0; j < 5; ++j) {
				for (int k = 0; k < 5; ++k) {
					if (j < k && f[i - 1][k]) {
						f[i][j] = 1;
						g[i][j] = k;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		if (f[n][i]) {
			getAns(n, i);
			std::cout << "\n";
			return 0;
		}
	}
	std::cout << -1 << "\n";
}