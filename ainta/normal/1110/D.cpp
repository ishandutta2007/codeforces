#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[1010000], C[1010000];
long long D[5][5], TD[5][5];
int main() {
	int i, j, k, l;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		w[i]++;
		C[w[i]]++;
	}
	m+=5;
	for (i = 0; i < 5; i++)for (j = 0; j < 5; j++)D[i][j] = -1e18;
	D[0][0] = 0;
	for (i = 2; i <= m; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 3; k++){
				TD[j][k] = D[j][k];
				D[j][k] = -1e18;
			}
		}
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 3; k++) {
				if (TD[j][k] < 0)continue;
				int c1 = C[i - 2] - j;
				int c2 = C[i - 1] - k;
				int cc = min(min(c1, c2), min(C[i], 2));
				for (l = 0; l <= cc; l++) {
					D[k + l][l] = max(D[k + l][l], TD[j][k] + l + (c1 - l) / 3);
				}
			}
		}
	}
	long long res = 0;
	for (i = 0; i < 5; i++)for (j = 0; j < 5; j++)res = max(res, D[i][j]);
	printf("%lld\n", res);
}