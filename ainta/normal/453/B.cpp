#pragma warning(disable:4996)
#include<stdio.h>
#define INF 999999999
int D[110][131072], c, w[20], n, a, p[61][131072], t, C[61], Ans[110];
int Path[110][131072];
int G[61];
int main()
{
	int i, j, k, x;
	for (i = 2; i <= 59; i++){
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)w[c++] = i;
	}
	scanf("%d", &n);
	for (i = 1; i <= 59; i++){
		t = (1 << c) - 1;
		for (j = 0; j < c; j++){
			if (i%w[j] == 0)t ^= (1 << j);
		}
		G[i] = (1 << c) - 1 - t;
		for (j = 0; j < (1 << c); j++){
			if ((t&j) == j)p[i][C[i]++] = j;
		}
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		for (j = 0; j < (1 << c); j++)D[i][j] = INF;
		for (j = 1; j <= 59; j++){
			t = a - j;
			if (t < 0)t = -t;
			for (k = 0; k < C[j]; k++){
				if (D[i][p[j][k] ^ G[j]] > D[i - 1][p[j][k]] + t){
					D[i][p[j][k] ^ G[j]] = D[i - 1][p[j][k]] + t;
					Path[i][p[j][k] ^ G[j]] = j;
				}
			}
		}
	}
	int Res = INF;
	for (i = 0; i < (1 << c); i++){
		if (Res > D[n][i])Res = D[n][i], x = i;
	}
	for (i = n; i >= 1; i--){
		Ans[i] = Path[i][x];
		x = x - G[Path[i][x]];
	}
	for (i = 1; i <= n; i++)printf("%d ", Ans[i]);
}