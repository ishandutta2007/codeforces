#include <bits/stdc++.h>

const int N = 100005;

int n, a[N][2];
bool f[N][2];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i][0] >> a[i][1];
	}
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			f[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				f[i][j] |= a[i - 1][k] >= a[i][j] && f[i - 1][k];
			}
		}
	}
	if (f[n][0] || f[n][1]) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}