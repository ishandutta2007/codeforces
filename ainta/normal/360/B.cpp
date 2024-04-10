#include<stdio.h>
int n, k, w[2010], D[2010], M, t, o[2010][2010], R;
long long B, E, tt;
int main()
{
	register int i, j;
	scanf("%d%d", &n, &k);
	if (n <= k+1){
		printf("0\n");
		return 0;
	}
	B = 0, E = 0;
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		if (i == 1)continue;
		if (E < w[i] - w[i - 1])E = w[i] - w[i - 1];
		if (E < w[i-1] - w[i])E = w[i-1] - w[i];
	}
	for (i = 2; i <= n; i++){
		for (j = 1; j < n; j++){
			t = w[i] - w[j];
			if (t < 0)t = -t;
			if (t == 0)o[i][j] = 0;
			else{
				o[i][j] = (t - 1) / (i - j) + 1;
			}
		}
	}
	while (B <= E){
		tt = (B + E + 1) >> 1;
		M = tt;
		for (i = 1; i <= n; i++)D[i] = 0;
		for (i = 1; i <= n; i++){
			D[i] = 1;
			for (j = 1; j < i; j++){
				if (o[i][j] <= M && D[i] < D[j] + 1)D[i] = D[j] + 1;
			}
			if (D[i]>=n - k)break;
		}
		if (i != n + 1){
			E = M - 1;
			R = M;
		}
		else B = M + 1;
	}
	printf("%d\n", R);
}