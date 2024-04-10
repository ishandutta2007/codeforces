#include<cstdio>
#include<algorithm>
using namespace std;
int w[110], n, C0, C1, D[110][110][2];
int main() {
	int i, j, k, l;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (i % 2 == 0)C0++;
		else C1++;
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			D[i][j][0]=D[i][j][1] = 1e9;
		}
	}
	D[0][0][0]=D[0][0][1] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < 2; k++) {
				int t = D[i - 1][j][k];
				if (w[i]) {
					if (w[i] % 2 == 0) {
						D[i][j + 1][0] = min(D[i][j + 1][0], t+(k!=0));
					}
					else {
						D[i][j][1] = min(D[i][j][1], t + (k!=1));
					}
				}
				else {
					for (l = 0; l < 2; l++) {
						D[i][j + 1 - l][l] = min(D[i][j + 1 - l][l], t + (k != l));
					}
				}
			}
		}
	}
	printf("%d\n", min(D[n][C0][0], D[n][C0][1]));
}