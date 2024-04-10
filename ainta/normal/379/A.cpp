#pragma warning(disable:4996)
#include<stdio.h>
int n, m, D[1010][1010], i, j;
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i <= n; i++){
		for (j = 0; j <= n - i; j++){
			if (j >= m)D[i][j] = D[i][j - m + 1] + 1;
			if (i && D[i][j] < D[i - 1][j + 1] + 1)D[i][j] = D[i - 1][j + 1] + 1;
		}
	}
	printf("%d\n", D[n][0]);
}