#include <bits/stdc++.h>

const int N = 105, M = 105;

int n, a[N], m, c[M], sum;
bool f[N][N * M];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
		sum += a[i];
		++c[a[i]];
	}
	
	int cnt = 0, ans = 0;
	for (int x = 1; x <= m; ++x) {
		if (c[x]) {
			++cnt;
			for (int j = 0; j <= c[x]; ++j) {
				for (int k = 0; k <= sum; ++k) {
					f[j][k] = 0;
				}
			}
			f[0][0] = 1;
			for (int i = 1; i <= n; ++i) {
				if (a[i] != x) {
					for (int j = c[x]; j; --j) {
						for (int k = sum; k >= a[i]; --k) {
							f[j][k] |= f[j - 1][k - a[i]];
						}
					}
				}
			}
			for (int i = 1; i <= c[x]; ++i) {
				if (f[i][i * x]) {
					break;
				} else {
					ans = std::max(ans, i);
				}
			}
		}
	}
	if (cnt <= 2) {
		std::cout << n << "\n";
	} else {
		std::cout << ans << "\n";
	}
}