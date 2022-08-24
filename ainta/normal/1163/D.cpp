#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char p[1010], s[60], t[60], tp[60];
int n, m, K, D[1010][60][60], SA[60][30][2];
void Calc(int L, char *a, int ck) {
	int i, j, k, l;
	for (i = 0; i <= L; i++) {
		for (j = 0; j < i; j++)tp[j] = a[j];
		for (j = 0; j < 26; j++) {
			tp[i] = j + 'a';

			for (k = min(i+1,L); k >= 1; k--) {
				for (l = 0; l < k; l++) {
					if (tp[i - k + 1 + l] != a[l])break;
				}
				if (l == k)break;
			}
			SA[i][j][ck] = k;
		}
	}
}
int main() {
	int i, j, k;
	scanf("%s%s%s", p, s, t);
	n = strlen(s);
	m = strlen(t);
	K = strlen(p);
	for (i = 0; i <= K; i++)for (j = 0; j <= n; j++)for (k = 0; k <= m; k++)D[i][j][k] = -1e9;
	D[0][0][0] = 0;
	Calc(n, s, 0);
	Calc(m, t, 1);
	for (i = 0; i < K; i++) {
		for (j = 0; j <= n; j++) {
			for (k = 0; k <= m; k++) {
				if (D[i][j][k] < -7e8)continue;
				for (int ch = 0; ch < 26; ch++) {
					if (p[i] != '*' && p[i] - 'a' != ch)continue;
					int nj = SA[j][ch][0], nk = SA[k][ch][1];
					int r = D[i][j][k];
					if (nj == n)r++;
					if (nk == m)r--;
					D[i + 1][nj][nk] = max(D[i + 1][nj][nk], r);
				}
			}
		}
	}
	int res = -1e9;
	for (i = 0; i <= n; i++)for (j = 0; j <= m; j++)res = max(res, D[K][i][j]);
	printf("%d\n", res);
}