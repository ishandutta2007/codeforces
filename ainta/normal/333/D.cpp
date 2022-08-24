#pragma warning(disable:4996)
#include<stdio.h>
int w[1010][1010], n, m, P[1010], c;
bool v[1010][1010];
int main()
{
	int B, E, M, R = 0, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
		}
	}
	B = 1, E = 1000000000;
	while (B <= E){
		M = (B + E) >> 1;
		for (i = 1; i <= m; i++)for (j = i + 1; j <= m; j++)v[i][j] = false;
		for (i = 1; i <= n; i++){
			c = 0;
			for (j = 1; j <= m; j++){
				if (w[i][j] >= M){
					for (k = 1; k <= c; k++){
						if (v[P[k]][j])break;
						v[P[k]][j] = true;
					}
					if (k != c + 1){
						break;
					}
					P[++c] = j;
				}
			}
			if (j != m + 1)break;
		}
		if (i != n + 1){
			R = M;
			B = M + 1;
		}
		else E = M - 1;
	}
	printf("%d\n", R);
}