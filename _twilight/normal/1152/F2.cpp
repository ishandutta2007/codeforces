#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int S = 16 * 13;
const int Mod = 1e9 + 7;

typedef class Matrix {
	public:
		int r, c;
		int a[S][S];
		
		Matrix() {	}
		Matrix(int r, int c) : r(r), c(c) {	}

		Matrix operator * (Matrix b) {
			Matrix rt (r, b.c);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < b.c; j++) {
					rt[i][j] = 0;
				}
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					for (int k = 0; k < b.c; k++) {
						rt[i][k] = (rt[i][k] + 1ll * a[i][j] * b[j][k]) % Mod;
					}
				}
			}
			return rt;
		}

		int* operator [] (int p) {
			return a[p];
		}
} Matrix;

int n, m, k;
int bit[16];
Matrix F0, T, pT;

int main() {
	scanf("%d%d%d", &n, &k, &m);
	int s = (k + 1) << m;
	F0.r = 1, F0.c = s;
	F0[0][0] = 1;
	T.r = s, T.c = s;
	int msk_and = (1 << m) - 1;
	for (int i = 1; i <= msk_and; i++)
		bit[i] = bit[i >> 1] + (i & 1);
	for (int c = 0; c <= k; c++) {
		for (int msk = 0; msk <= msk_and; msk++) {
			int nmsk = (msk << 1) & msk_and;
			T[(c << m) | msk][(c << m) | nmsk]++;
			if (c < k) {
				T[(c << m) | msk][((c + 1) << m) | nmsk | 1] += bit[msk] + 1;
			}
		}
	}
	pT.r = s, pT.c = s;
	for (int i = 0; i < s; i++) {
		pT[i][i] = 1;
	}
	for ( ; n; n >>= 1, T = T * T) {
		if (n & 1) {
			pT = pT * T;
		}
	}
	F0 = F0 * pT;
	int ans = 0;
	for (int msk = 0; msk <= msk_and; msk++) {
		ans += F0[0][(k << m) | msk];
		(ans >= Mod) && (ans -= Mod);
	}
	printf("%d\n", ans);
	return 0;
}