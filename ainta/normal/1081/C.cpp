#include<cstdio>
#include<algorithm>
using namespace std;
int D[2010][2010], Mod = 998244353, n, m, K;
int main() {
	scanf("%d%d%d", &n, &m, &K);
	D[1][0] = m;
	int i, j;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < i; j++) {
			D[i][j] = (D[i][j] + D[i-1][j]) % Mod;
			D[i][j + 1] = (D[i][j+1] + 1ll * D[i-1][j] * (m - 1)) % Mod;
		}
	}
	printf("%d\n", D[n][K]);
}