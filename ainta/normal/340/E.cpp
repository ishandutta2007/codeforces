#pragma warning(disable:4996)
#include<stdio.h>
long long D[2010][2010], Mod = 1000000007;
int i, j, n, C[2010], a, c1, c2;
int main(){
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		if (a != -1)C[a]++, C[i]++;
	}
	for (i = 1; i <= n; i++){
		if (C[i] == 1)c2++;
		if (!C[i])c1++;
	}
	c2 /= 2;
	D[0][0] = 1;
	for (i = 1; i <= c2 + c1; i++)D[0][i] = D[0][i - 1] * i %Mod;
	for (i = 0; i <= c2 + c1; i++)D[1][i] = D[0][i] * i % Mod;
	for (i = 2; i <= c1; i++){
		for (j = 0; j <= c2 + c1 - i; j++){
			D[i][j] = (D[i - 2][j + 1] * (i - 1) + D[i - 1][j] * j) % Mod;
		}
	}
	printf("%lld\n", D[c1][c2]);
}