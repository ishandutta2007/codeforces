#pragma warning(disable:4996)
#include<stdio.h>
char p[5010][5010];
int n, m, i, j, w[5010][5010], C[5010], k, T[5010], S, Res;
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (p[i][j] == '1'){
				w[i][j] = w[i][j - 1] + 1;
			}
		}
	}
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			C[w[j][i]]++;
		}
		S = 0;
		for (j = m; j >= 1; j--){
			S += C[j];
			if (j*S > Res)Res = j*S;
			C[j] = 0;
		}
	}
	printf("%d\n", Res);
}