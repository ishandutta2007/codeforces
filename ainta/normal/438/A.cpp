#pragma warning(disable:4996)
#include<stdio.h>
int n, m, w[1010], res, i;
int main()
{
	int a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		res += w[a] < w[b] ? w[a] : w[b];
	}
	printf("%d\n", res);
}