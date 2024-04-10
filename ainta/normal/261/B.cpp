#pragma warning(disable:4996)
#include<stdio.h>
int n, p, w[51], s;
double D[51][51][51], Res, S;
int main()
{
	int i, ii, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		s += w[i];
	}
	scanf("%d", &p);
	if (s <= p){
		printf("%.10lf\n", (double)n);
		return 0;
	}
	D[0][0][0] = 1.0;
	for (i = 1; i <= n; i++){
		for (ii = 0; ii < i; ii++){
			for (j = 0; j <= p; j++){
				D[i][ii][j] += D[i - 1][ii][j] * (double)(i - ii) / i;
				if (j + w[i]>p)continue;
				D[i][ii + 1][j + w[i]] += D[i - 1][ii][j] * (double)(ii + 1) / i;
			}
		}
	}
	for (i = 1; i <= n; i++){
		S = 0;
		for (j = 0; j <= p; j++){
			S += D[n][i][j];
		}
		Res += S;
	}
	printf("%.10lf\n", Res);
}