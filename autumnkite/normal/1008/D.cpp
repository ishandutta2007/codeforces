#include <bits/stdc++.h>

const int N = 100005;

int A, B, C;
int d[N];
int bitcnt[8];
bool can[8][8][8];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			++d[j];
		}
	}
	
	bitcnt[0] = 0;
	for (int i = 1; i < 8; ++i) {
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	}
	for (int i = 1; i < 8; ++i) {
		for (int j = 1; j < 8; ++j) {
			for (int k = 1; k < 8; ++k) {
				int p[3] = {0, 1, 2};
				bool flag = 0;
				do {
					flag |= (i >> p[0] & 1) & (j >> p[1] & 1) & (k >> p[2] & 1);
				} while (!flag && std::next_permutation(p, p + 3));
				can[i][j][k] = flag;
			}
		}
	}
	
	int T = 1;
	std::cin >> T;
	while (T--) {
		int A[3];
		std::cin >> A[0] >> A[1] >> A[2];
		long long ans = 0;
		int g[8], f[8];
		for (int S = 1; S < 8; ++S) {
			g[S] = 0;
			for (int i = 0; i < 3; ++i) {
				if (S >> i & 1) {
					g[S] = std::__gcd(g[S], A[i]);
				}
			}
		}
		for (int S = 1; S < 8; ++S) {
			f[S] = 0;
			for (int T = S; T < 8; T = (T + 1) | S) {
				f[S] += (bitcnt[T ^ S] & 1 ? -1 : 1) * d[g[T]];
			}
		}
		for (int i = 1; i < 8; ++i) {
			for (int j = 1; j < 8; ++j) {
				for (int k = 1; k < 8; ++k) {
					if (can[i][j][k]) {
						if (i == j && i == k) {
							ans += 1ll * f[i] * (f[i] - 1) * (f[i] - 2);
							ans += 3ll * f[i] * (f[i] - 1) * 2;
							ans += f[i] * 6;
							continue;
						}
						if (i == j) {
							ans += 1ll * f[i] * (f[i] - 1) * f[k];
							ans += 1ll * f[i] * f[k] * 2;
							continue;
						}
						if (i == k) {
							ans += 1ll * f[i] * (f[i] - 1) * f[j];
							ans += 1ll * f[i] * f[j] * 2;
							continue;
						}
						if (j == k) {
							ans += 1ll * f[j] * (f[j] - 1) * f[i];
							ans += 1ll * f[j] * f[i] * 2;
							continue;
						}
						ans += 1ll * f[i] * f[j] * f[k];
					}
				}
			}
		}
		std::cout << ans / 6 << "\n";
	}
}