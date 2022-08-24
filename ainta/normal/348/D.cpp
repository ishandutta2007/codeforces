#pragma warning(disable:4996)
#include<stdio.h>
char p[3010][3010];
int n, m, i, j, Mod = 1000000007, D[2][3010], x, D2[2][3010];
long long res;
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		x = !x;
		scanf("%s", p[i] + 1);
		for (j = 1; j <= m; j++){
			if (p[i][j] == '#'){
				D[x][j] = D2[x][j] = 0;
				continue;
			}
			if(i != 1 || j != 2)D[x][j] = (D[x][j - 1] + D[!x][j]) % Mod;
			else D[x][j] = 1;
			if (i != 2 || j != 1)D2[x][j] = (D2[x][j - 1] + D2[!x][j]) % Mod;
			else D2[x][j] = 1;
		}
	}
	res = (long long)D[!x][m] * D2[x][m - 1] % Mod;
	res -= (long long)D[x][m - 1] * D2[!x][m] % Mod;
	printf("%lld\n", (res+Mod)%Mod);
}