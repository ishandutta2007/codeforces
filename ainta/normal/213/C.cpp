#pragma warning(disable:4996)
#include<stdio.h>
int w[301][301], n, D[301][301][301];
int main()
{
	int i, j, k, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			for (k = 1; k <= n; k++)D[i][j][k] = -999999999;
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			D[1][i][j] = 0;
			for (k = 1; k <= j; k++){
				D[1][i][j] += w[1][k];
			}
		}
	}
	for (i = 2; i <= n; i++){
		for (j = 1; j <= n; j++){
			for (k = 1; k <= n; k++){
				t = w[i][j] + w[i][k];
				if (j == k)t = w[i][j];
				D[i][j][k] = D[i - 1][j][k] + t;
			}
		}
		for (j = 2; j <= n; j++){
			for (k = j; k <= n; k++){
				t = w[i][j];
				if (j == k)t = 0;
				t += D[i][j - 1][k];
				if (D[i][j][k] < t)D[i][j][k] = t;
			}
		}
		for (j = 2; j <= n; j++){
			if (D[i][j][j] < D[i][j - 1][j - 1] + w[i][j])D[i][j][j] = D[i][j - 1][j - 1] + w[i][j];
		}
		for (j = 1; j <= n; j++){
			for (k = j + 1; k <= n; k++){
				t = D[i][j][k - 1] + w[i][k];
				if (D[i][j][k] < t)D[i][j][k] = t;
			}
		}
	}
	printf("%d\n", D[n][n][n]);
}