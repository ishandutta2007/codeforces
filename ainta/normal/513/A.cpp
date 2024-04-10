#include<stdio.h>
int n1, n2, k1, k2;
int main()
{
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	if (n1 <= n2)printf("Second\n");
	else printf("First\n");
}