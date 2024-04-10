#pragma warning(disable:4996)
#include<stdio.h>
int n, k, m, Mod = 1000000007, R;
int D[12][2048], TD[12][2048];
int P[2][12][2048][2];
int main(){
	int i, a, j, x1, y1, x2, y2;
	scanf("%d%d", &n, &m);
	m--;
	for (i = 0; i < m; i++){
		for (j = 1; j < 2048; j++){
			P[0][i][j][0] = i;
			P[0][i][j][1] = j + 1;
			if ((j + 1) >> (i + 1))P[0][i][j][0] = i+1;
			if (j & 1){
				P[1][i][j][0] = i < 1 ? 1 : i;
				P[1][i][j][1] = 2;
			}
			else{
				P[1][i][j][0] = i;
				P[1][i][j][1] = j + 2;
				if ((j + 2) >> (i + 1))P[1][i][j][0] = i + 1;
			}
		}
	}
	for (j = 0; j < 2048; j++){
		P[0][m][j][0] = m, P[0][m][j][1] = 0;
		P[1][m][j][0] = m, P[1][m][j][1] = 0;
	}
	scanf("%d", &a);
	if (!a || a == 2)D[0][1]++;
	if (!a || a == 4)D[1][2]++;
	for (i = 1; i < n; i++){
		scanf("%d", &a);
		for (j = 0; j <= m; j++){
			for (k = 0; k < 2048; k++){
				x1 = P[0][j][k][0], y1 = P[0][j][k][1];
				x2 = P[1][j][k][0], y2 = P[1][j][k][1];
				if (a == 2 || !a)TD[x1][y1] = (TD[x1][y1] + D[j][k]) % Mod;
				if (a == 4 || !a)TD[x2][y2] = (TD[x2][y2] + D[j][k]) % Mod;
			}
		}
		for (j = 0; j <= m; j++){
			for (k = 0; k < 2048; k++){
				D[j][k] = TD[j][k];
				TD[j][k] = 0;
			}
		}
	}
	for (i = 0; i < 2048; i++)R = (R + D[m][i]) % Mod;
	printf("%d\n", R);
}