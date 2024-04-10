#include<cstdio>
#include<algorithm>
using namespace std;
int m, n, Mod = 1000000007;
char p[60][1010];
int C[1010], D[1010], Comb[1010][1010];
int main() {
	int i, j, res = 0, k;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i]);
	}
	int Com = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < i; j++) {
			for (k = 1; k <= n; k++) {
				if (p[k][i] != p[k][j])break;
			}
			if (k == n + 1) {
				break;
			}
		}
		C[j]++;
	}
	for (i = 0; i <= m; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
	}
	D[0] = 1;
	for (i = 1; i <= m; i++) {
		int s = 0;
		for (j = 0; j < i; j++) {
			s = (s + 1ll * Comb[i - 1][j] * D[j]) % Mod;
		}
		D[i] = s;
	}
	res = 1;
	for (i = 0; i < m; i++) {
		res = 1ll * res*D[C[i]] % Mod;
	}
	printf("%d\n", res);
}