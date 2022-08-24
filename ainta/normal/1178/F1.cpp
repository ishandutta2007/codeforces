#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int chk[510], w[510], Mod = 998244353;
long long D[510][510], DD[510][510];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n+1; i++)DD[i][i-1] = D[i][i - 1] = 1;
	for (int l = 1; l <= n; l++) {
		for (i = 1; i <= n - l + 1; i++) {
			int b = i, e = i + l - 1;
			if (l == 1) {
				DD[b][e] = D[b][e] = 1;
				continue;
			}
			int Mn = 1e9, pv = -1;
			for (j = b; j <= e; j++) {
				if (Mn > w[j])Mn = w[j], pv = j;
			}
			DD[b][e] = (DD[b][e] + D[b][pv - 1] * D[pv + 1][e]) % Mod;
			D[b][e] = DD[b][e];
			for (j = b; j < e; j++) {
				D[b][e] = (D[b][e] + DD[b][j] * D[j + 1][e]) % Mod;
			}
		}
	}
	printf("%lld\n", D[1][n]);
}