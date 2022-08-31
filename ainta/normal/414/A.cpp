#pragma warning(disable:4996)
#include<stdio.h>
double P, S;
int main()
{
	int n, K, i, c, t;
	scanf("%d%d", &n, &K);
	if (n == 1){
		if (!K)printf("3\n");
		else printf("-1\n");
		return 0;
	}
	if (n / 2 > K){
		printf("-1\n");
		return 0;
	}
	c = n / 2 - 1;
	for (i = 1; i <= c; i++){
		printf("%d %d ", i * 2 - 1, i * 2);
	}
	t = n / (K - c) * (K - c);
	printf("%d %d", t + K - c , t + (K - c)*2);
	if (n % 2 == 0)printf("\n");
	else printf(" %d\n", t + (K - c) * 3);
}