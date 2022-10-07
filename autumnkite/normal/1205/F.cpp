#include <bits/stdc++.h>

const int N = 105, M = N * (N - 1) / 2;

bool f[N][M];
int g[N][M];

void init(int n) {
	f[1][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i * (i - 1) / 2; ++j) {
			if (f[i][j]) {
				for (int k = 2; k <= n + 1 - i; ++k) {
					f[i + k - 1][j + k * (k - 1) / 2] = true;
					g[i + k - 1][j + k * (k - 1) / 2] = k;
				}
				for (int k = 4; k <= n + 1 - i; ++k) {
					f[i + k - 1][j + 1] = true;
					g[i + k - 1][j + 1] = -k;
				}
			}
		}
	}
}

void solve(std::deque<int> &Q, int n, int m, bool op = 0) {
	if (n == 1) {
		Q.push_back(1);
		return;
	}
	int k = g[n][m];
	if (k > 0) {
		solve(Q, n - k + 1, m - k * (k - 1) / 2, !op);
		if (op == 0) {
			for (int i = n - k + 2; i <= n; ++i) {
				Q.push_back(i);
			}
		} else {
			for (int i = n - k + 2; i <= n; ++i) {
				Q.push_front(i);
			}
		}
	} else {
		k = -k;
		solve(Q, n - k + 1, m - 1);
		for (int i = k - (k & 1); i >= 2; i -= 2) {
			Q.push_front(n - k + i);
		}
		if (k & 1) {
			for (int i = k; i >= 3; i -= 2) {
				Q.push_back(n - k + i);
			}
		} else {
			for (int i = 3; i <= k; i += 2) {
				Q.push_back(n - k + i);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init(100);
	int T = 1;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		m -= n;
		if (m < 0 || m > n * (n - 1) / 2 || !f[n][m]) {
			std::cout << "NO\n";
			continue;
		}
		std::deque<int> Q;
		solve(Q, n, m);
		std::cout << "YES\n";
		for (int v : Q) {
			std::cout << v << " ";
		}
		std::cout << "\n";
	}
}