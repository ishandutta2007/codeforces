#pragma warning(disable:4996)
#include<stdio.h>
int n, m, Q, i, j, k, l,D[41][41][41][41], x, y, Res;
char p[50][50];
bool v[41][41];
int main()
{
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			for (k = i; k >= 1; k--){
				for (l = j; l >= 1; l--){
					if (k == i && l == j)v[k][l] = (p[k][l] == '0');
					else if (k == i) v[k][l] = v[k][l + 1] && (p[k][l] == '0');
					else if (l == j) v[k][l] = v[k + 1][l] && (p[k][l] == '0');
					else v[k][l] = v[k + 1][l] && v[k][l + 1] && (p[k][l] == '0');
					x = i - k + 1;
					y = j - l + 1;
					D[i][j][x][y] = D[i][j - 1][x][y] + D[i - 1][j][x][y] - D[i - 1][j - 1][x][y] + (v[k][l] == true);
				}
			}
		}
	}
	while(Q--){
		scanf("%d%d%d%d", &i, &j, &k, &l);
		Res = 0;
		for (x = 1; x <= k-i+1; x++){
			for (y = 1; y <= l-j+1; y++){
				Res += D[k][l][x][y] - D[i + x - 2][l][x][y] - D[k][j + y - 2][x][y] + D[i + x - 2][j + y - 2][x][y];
			}
		}
		printf("%d\n", Res);
	}
}