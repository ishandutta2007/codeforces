#include <bits/stdc++.h>

const int N = 100005;

int n, a[N], b[N];
bool f[N][4];
int g[N][4];

void getAns(int k, int x) {
	if (k > 1) {
		getAns(k - 1, g[k][x]);
	}
	std::cout << x << " ";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < 4; ++i) {
		f[1][i] = true;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {
			f[i][j] = 0;
			for (int k = 0; k < 4; ++k) {
				if ((j | k) == a[i - 1] && (j & k) == b[i - 1] && f[i - 1][k]) {
					f[i][j] = 1;
					g[i][j] = k;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (f[n][i]) {
			std::cout << "YES\n";
			getAns(n, i);
			std::cout << "\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}