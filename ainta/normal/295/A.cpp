#pragma warning(disable:4996)
#include<stdio.h>
int C[101000], i, n, m, Q, S[100010];
int w[101000][3], a, b, A[100010];
long long S2[100010];
int main()
{
	scanf("%d%d%d", &n,&m,&Q);
	for (i = 1; i <= n; i++){
		scanf("%lld", &A[i]);
	}
	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &w[i][0], &w[i][1], &w[i][2]);
	}
	for (i = 0; i < Q; i++){
		scanf("%d%d", &a, &b);
		S[a]++, S[b + 1]--;
	}
	for (i = 1; i <= m; i++)S[i] += S[i - 1];
	for (i = 1; i <= m; i++){
		S2[w[i][0]] += (long long)S[i]*w[i][2];
		S2[w[i][1] + 1] -= (long long)S[i] * w[i][2];
	}
	for (i = 1; i <= n; i++)S2[i] += S2[i - 1];
	for (i = 1; i <= n; i++){
		printf("%lld ", S2[i] + A[i]);
	}
}