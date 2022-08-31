#pragma warning(disable:4996)
#include<stdio.h>
#define INF 3000000000000000000LL
int CX[4010], CY[4010], n, m, x, y;
long long M, S = 0, Res;
int main()
{
	int i, j, a;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &a);
			CX[i * 4 - 2] += a;
			CY[j * 4 - 2] += a;
		}
	}
	M = INF;
	for (i = 0; i <= 4000; i += 4){
		S = 0;
		for (j = 2; j <= 4000; j += 4){
			S += (long long)CX[j] * (j - i)*(j - i);
		}
		if (M > S)M = S, x = i;
	}
	Res += M;
	M = INF;
	for (i = 0; i <= 4000; i += 4){
		S = 0;
		for (j = 2; j <= 4000; j += 4){
			S += (long long)CY[j] * (j - i)*(j - i);
		}
		if (M > S)M = S, y = i;
	}
	Res += M;
	printf("%lld\n", Res);
	printf("%d %d\n", x/4, y/4);
}