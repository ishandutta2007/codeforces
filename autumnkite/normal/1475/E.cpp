#include <bits/stdc++.h>

const int N = 1005, P = 1000000007;

int C[N][N];

int n, m;
int a[N];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n, std::greater<int>());
	int l = m, r = m;
	while (l > 1 && a[l - 1] == a[m]) {
		--l;
	}
	while (r < n && a[r + 1] == a[m]) {
		++r;
	}
	std::cout << C[r - l + 1][m - l + 1] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}