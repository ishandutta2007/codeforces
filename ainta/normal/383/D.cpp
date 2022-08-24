#pragma warning(disable:4996)
#include<stdio.h>
#define Mod 1000000007
int n, i, a, D[1010][20100], j, Res;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		for (j = 0; j <= 20000; j++){
			if (!D[i - 1][j])continue;
			D[i][j - a] = (D[i][j - a] + D[i - 1][j]) % Mod;
			D[i][j + a] = (D[i][j + a] + D[i - 1][j]) % Mod;
		}
		D[i][10000 - a]++, D[i][10000 + a]++;
		Res = (Res + D[i][10000]) % Mod;
	}
	printf("%d\n", Res);
}