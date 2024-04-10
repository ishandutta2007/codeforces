#pragma warning(disable:4996)
#include<stdio.h>
int n, w[201000], i, L[201000], R[201000];
long long Res, C;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		if (w[i])C++;
		else Res += C;
	}
	printf("%lld\n", Res);
}