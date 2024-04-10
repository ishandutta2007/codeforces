#pragma warning(disable:4996)
#include<stdio.h>
double D[2][1010], P1, P2, P[2][1010], Res, PP[1010][3];
int n, k;
int main()
{
	int i, j, x;
	scanf("%d%d", &n, &k);
	P1 = 1.0 / k;
	P[0][1] = 1.0;
	for (i = 1; i <= 1000; i++){
		PP[i][0] = 1.0 - 1.0 / (1.0 + i) / (double)k;
		PP[i][1] = 1.0 / (double)i / (double)k;
		PP[i][2] = 1.0 / i*P1;
	}
	for (i = 1; i <= n; i++){
		x = i&1;
		for (j = 1; j <= 1000 && j <= i + 1; j++){
			P[x][j] = D[x][j] = 0;
			P[x][j] += P[!x][j] * PP[j][0];
			P[x][j] += P[!x][j - 1] * PP[j][1];
			D[x][j] = D[!x][j] * (1.0 - P1);
			P2 = (double)j / (double)(j + 1);
			D[x][j] += (D[!x][j] + (1.0 + j)*0.5 * P[!x][j]) * P1 * P2;
			if (j != 1) D[x][j] += (D[!x][j - 1] + (j - 1) * P[!x][j-1])* PP[j][2];
			if (P[x][j] < 1e-200)P[x][j] = 0;
			if (D[x][j] < 1e-200)D[x][j] = 0;
		}
	}
	for (i = 1; i <= 1000 && i <= n + 1; i++){
		Res += D[n&1][i];
	}
	printf("%.11lf\n", Res*k);
	return 0;
}