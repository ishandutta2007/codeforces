#include <bits/stdc++.h>

const int N = 1000005, M = 5005;

int n, m, P, mx, a[N], f[M][M], A[M], fac[M], g[2][M];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n >> m >> P;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	
	A[0] = fac[0] = 1;
	for (int i = 1; i <= mx && i <= m; ++i) {
		A[i] = 1ll * A[i - 1] * (m - i + 1) % P;
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	f[0][0] = 1;
	for (int i = 1; i <= mx; ++i) {
		for (int j = 1; j <= i; ++j) {
			f[i][j] = (f[i - 1][j - 1] + 1ll * f[i - 1][j] * (j - 1)) % P;
		}
	}
	int u = 0;
	g[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		u ^= 1;
		int sum = 0;
		for (int j = 0; j <= m && j <= a[i - 1]; ++j) {
			sum = (sum + g[u ^ 1][j]) % P;
		}
		for (int j = 0; j <= m && j <= a[i]; ++j) {
			g[u][j] = 1ll * (sum + P - g[u ^ 1][j]) * f[a[i]][j] % P * A[j] % P;
			g[u][j] = (g[u][j] + 1ll * (A[j] + P - fac[j]) * f[a[i]][j] % P * g[u ^ 1][j]) % P;
		}
		for (int j = 0; j <= m && j <= a[i - 1]; ++j) {
			g[u ^ 1][j] = 0;
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= mx && i <= m; ++i) {
		ans = (ans + g[u][i]) % P;
	}
	std::cout << ans << "\n";
}