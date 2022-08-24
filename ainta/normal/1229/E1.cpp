#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int w[10][10], Mod = 1000000007;
int  E[10][10], vis[10];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int CC[63], CB[30];
long long D[1 << 20], D2[1 << 20];
int main() {
	int i, j, k, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
			w[i][j] = w[i][j] * Pow(100, Mod - 2) % Mod;
		}
	}
	if (n <= 4) {
		long long res = 0;
		for (i = 0; i < (1 << (n*n)); i++) {
			long long p = 1;
			int BB[10] = { 0 };
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					int t = j * n + k;
					if ((i >> t) & 1) {
						BB[j] |= (1 << k);
						p = p * w[j][k] % Mod;
					}
					else p = p * (1 - w[j][k] + Mod) % Mod;
				}
			}
			int UU[5];
			for (j = 0; j < n; j++)UU[j] = j;
			int chk = 0;
			do {
				for (j = 0; j < n; j++) {
					if (!((BB[j] >> UU[j]) & 1))break;
				}
				if (j == n)chk = 1;
			} while (next_permutation(UU, UU + n));
			if (chk)res = (res + p) % Mod;
		}
		printf("%lld\n", res);
		return 0;
	}

	if (n == 5) {

		int cnt = 0;
		for (i = 0; i < (1 << 5); i++) {
			int c = 0;
			for (int j = 0; j < 5; j++) {
				if ((i >> j) & 1)c++;
			}
			if (c == 3) {
				CB[cnt] = i;
				CC[i] = cnt++;
			}
		}
		for (i = 0; i < (1 << (2 * n)); i++) {
			long long p = 1;
			for (j = 0; j < 2; j++) {
				for (k = 0; k < n; k++) {
					int t = j * n + k;
					if ((i >> t) & 1) {
						E[j][k] = 1;
						p = p * w[j][k] % Mod;
					}
					else {
						p = p * (1 - w[j][k] + Mod) % Mod;
						E[j][k] = 0;
					}
				}
			}
			int mask = 0;
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
						if (j != k && E[0][j] && E[1][k]) {
							int u = 31 - (1 << j) - (1 << k);
							mask |= (1 << CC[u]);
						}
				}
			}
			D[mask] = (D[mask] + p) % Mod;
		}

		for (i = 0; i < 10; i++) {
			for (j = 0; j < (1 << 10); j++) {
				if ((j >> i) & 1)continue;
				D[j | (1 << i)] = (D[j]+ D[j | (1 << i)])%Mod;
			}
		}
		for (i = 0; i < (1 << (3 * n)); i++) {
			long long p = 1;
			for (j = 0; j < 3; j++) {
				for (k = 0; k < n; k++) {
					int t = j * n + k;
					if ((i >> t) & 1) {
						E[j + 2][k] = 1;
						p = p * w[j + 2][k] % Mod;
					}
					else {
						p = p * (1 - w[j + 2][k] + Mod) % Mod;
						E[j + 2][k] = 0;
					}
				}
			}
			int mask = 0;
			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					for (l = 0; l < n; l++) {
						if (j != k && j != l && k != l && E[2][j] && E[3][k] && E[4][l]) {
							int u = (1 << j) + (1 << k) + (1 << l);
							mask |= (1 << CC[u]);
						}
					}
				}
			}
			if (p) {
				D2[mask] = (D2[mask] + p) % Mod;
			}
		}
		long long res = 0;
		for (i = 0; i < (1 << 10); i++) {
			res = (res + (D[(1 << 10) - 1] - D[(1 << 10) - 1 - i] + Mod)*D2[i]) % Mod;
		}
		printf("%lld\n", res);
		return 0;
	}


	int cnt = 0;
	for (i = 0; i < (1 << 6); i++) {
		int c = 0;
		for (int j = 0; j < 6; j++) {
			if ((i >> j) & 1)c++;
		}
		if (c == 3) {
			CB[cnt] = i;
			CC[i] = cnt++;
		}
	}
	for (i = 0; i < (1 << (3*n)); i++) {
		long long p = 1;
		for (j = 0; j < 3; j++) {
			for (k = 0; k < n; k++) {
				int t = j * n + k;
				if ((i >> t) & 1) {
					E[j][k] = 1;
					p = p * w[j][k] % Mod;
				}
				else {
					p = p * (1 - w[j][k] + Mod) % Mod;
					E[j][k] = 0;
				}
			}
		}
		int mask = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				for (l = 0; l < n; l++) {
					if (j != k && j != l && k != l && E[0][j] && E[1][k] && E[2][l]) {
						int u = 63 - (1 << j) - (1 << k) - (1 << l);
						mask |= (1 << CC[u]);
					}
				}
			}
		}
		D[mask] = (D[mask] + p) % Mod;
	}

	for (i = 0; i < 20; i++) {
		for (j = 0; j < (1 << 20); j++) {
			if ((j >> i) & 1)continue;
			D[j | (1 << i)] = (D[j] + D[j | (1 << i)]) % Mod;
		}
	}
	for (i = 0; i < (1 << (3 * n)); i++) {
		long long p = 1;
		for (j = 0; j < 3; j++) {
			for (k = 0; k < n; k++) {
				int t = j * n + k;
				if ((i >> t) & 1) {
					E[j+3][k] = 1;
					p = p * w[j+3][k] % Mod;
				}
				else {
					p = p * (1 - w[j+3][k] + Mod) % Mod;
					E[j+3][k] = 0;
				}
			}
		}
		int mask = 0;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				for (l = 0; l < n; l++) {
					if (j != k && j != l && k != l && E[3][j] && E[4][k] && E[5][l]) {
						int u = (1 << j) + (1 << k) + (1 << l);
						mask |= (1 <<CC[u]);
					}
				}
			}
		}
		D2[mask] = (D2[mask] + p) % Mod;
	}
	long long res = 0;
	for (i = 0; i < (1 << 20); i++) {
		res = (res + (D[(1 << 20) - 1] - D[(1 << 20) - 1 - i] + Mod)*D2[i]) % Mod;
	}
	printf("%lld\n", res);
}