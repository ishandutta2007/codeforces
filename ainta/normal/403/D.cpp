#pragma warning(disable:4996)
#include<stdio.h>
int P[2][1010][1010], D[1010][51], Mod = 1000000007, F[1010];
long long LMod = 1000000007, Res[1010][51];
int C[1100][1100];
int main()
{
	int i, j, pv = 0, k, cnt = 0, N, K, T;
	for (i = 0; i <= 1000; i++){
		for (j = i; j <= 1000; j++)P[0][i][j] = 1;
		D[i][1] = 1;
	}
	for (i = 0; i <= 1010; i++){
		C[i][0] = 1;
		for (j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
		}
	}
	for (i = 2; i <= 50; i++){
		cnt += (i - 1);
		for (j = cnt; j <= 1000; j++){
			for (k = i - 1; k <= 1000; k++){
				P[!pv][j][k] = P[!pv][j][k - 1];
				if (j >= k) P[!pv][j][k] = (P[!pv][j][k] + P[pv][j - k][k - 1]) % Mod;
			}
			D[j][i] = P[!pv][j][1000];
		}
		for (j = 0; j <= 1000; j++)for (k = 0; k <= 1000; k++)P[pv][j][k] = 0;
		pv = !pv;
	}
	F[0] = 1;
	long long tp;
	for (i = 1; i <= 1000; i++){
		tp = F[i - 1];
		tp = tp * i % LMod;
		F[i] = tp;
	}
	scanf("%d", &T);
	for (N = 0; N <= 1000; N++){
		for (K = 1; K < 50; K++){
			for (i = 0; i <= N - K + 1; i++){
				tp = D[i][K];
				tp = tp * F[K] % LMod;
				tp = tp * C[N - i + 1][N - K + 1 - i] % LMod;
				Res[N][K] = (Res[N][K] + tp) % LMod;
			}
		}
	}
	while (T--){
		scanf("%d%d", &N, &K);
		if (K >= 50){
			printf("0\n");
			continue;
		}
		printf("%lld\n", Res[N - 1][K]);
	}
	return 0;
}