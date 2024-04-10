#include <bits/stdc++.h>

const int N = 100005;

int n, d, inv[N << 1], P, Inv2;

int c[N];

void getp(int l, int r, int dep) {
	if (dep <= 1 || l == r) {
		++c[r - l + 1];
		return;
	}
	int mid = (l + r) >> 1;
	getp(l, mid, dep - 1);
	getp(mid + 1, r, dep - 1);
}

int ans;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> d >> P;
	inv[1] = 1;
	for (int i = 2; i <= n + n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}
	Inv2 = inv[2];
	getp(1, n, d);

	for (int i = 1; i <= n; ++i) {
		if (c[i]) {
			ans = (ans + 1ll * i * (i - 1) / 2 % P * Inv2 % P * c[i]) % P;
			for (int j = i; j <= n; ++j) {
				if (c[j]) {
					int sum = 0;
					for (int k = 2; k <= i + j; ++k) {
						int t = std::min(i, k - 1) - std::max(1, k - j) + 1;
						sum = (sum + 1ll * t * (k - 2) % P * inv[k]) % P;
					}
					sum = 1ll * sum * Inv2 % P;
					int t = i == j ? 1ll * c[i] * (c[i] - 1) / 2 % P : 1ll * c[i] * c[j] % P;
					ans = (ans + 1ll * t * sum) % P;
				}
			}
		}
	}
	std::cout << ans << std::endl;
}