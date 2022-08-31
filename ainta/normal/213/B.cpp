#pragma warning(disable:4996)
#include<stdio.h>
long long C[101][101], Mod = 1000000007, Res, D[10][101];
int cnt[10], ori[10];
long long Gap(int n){
	int i, j, k;
	for (i = 0; i < 10; i++)for (j = 0; j <= n; j++)D[i][j] = 0;
	for (i = cnt[0]; i <= n; i++)D[0][i] = C[n][i];
	for (i = 1; i < 10; i++){
		for (j = 0; j <= n; j++){
			for (k = cnt[i]; k <= n - j; k++){
				D[i][j + k] = (D[i][j + k] + D[i - 1][j] * C[n - j][k]) % Mod;
			}
		}
	}
	return D[9][n];
}
int main()
{
	int i, j, k, n;
	for (i = 0; i <= 100; i++){
		C[i][0] = 1;
		for (j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
		}
	}
	scanf("%d", &n);
	for (i = 0; i < 10; i++){
		scanf("%d", &ori[i]);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= 9; j++){
			for (k = 0; k < 10; k++)cnt[k] = ori[k];
			if (cnt[j])cnt[j]--;
			Res = (Res + Gap(i - 1)) % Mod;
		}
	}
	printf("%lld\n", Res);
}