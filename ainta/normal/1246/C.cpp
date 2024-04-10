#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[2010][2010], S[2010][2010];
long long D[2010][2010], R[2010][2010], Mod = 1000000007, S1[2010][2010], S2[2010][2010];
char p[2010][2010];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i]+1);
		for (j = 1; j <= m; j++) {
			if (p[i][j] == 'R') {
				w[i][j] = 1;
			}
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + w[i][j];
		}
	}
	if (n == 1 && m == 1) {
		puts("1");
		return 0;
	}
	for (j = 2; j <= m - S[1][m]; j++)R[1][j] = 1;
	for (j = 2; j <= n - S[n][1]; j++)D[j][1] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			S1[i][j] += S1[i][j - 1];
			S2[i][j] += S2[i - 1][j];
			R[i][j] = (R[i][j] + S1[i][j]) % Mod;
			D[i][j] = (D[i][j] + S2[i][j]) % Mod;
			int dc = (S[n][j] - S[n][j - 1]) - (S[i][j] - S[i][j - 1]);
			int rc = (S[i][m] - S[i - 1][m]) - (S[i][j] - S[i - 1][j]);
			S1[i][j + 1] += D[i][j];
			S1[i][m - rc + 1] -= D[i][j];
			S2[i + 1][j] += R[i][j];
			S2[n - dc + 1][j] -= R[i][j];
		}
	}
	printf("%lld\n", (R[n][m] + D[n][m]) % Mod);
}