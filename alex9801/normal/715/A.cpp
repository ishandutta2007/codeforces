#include <stdio.h>
#include <string.h>
#include <algorithm>

int main()
{
	int n, i;
	scanf("%d", &n);
	printf("2\n");
	for(i = 2; i<=n; i++)
		printf("%lld\n", 1LL*i*(i+1)*(i+1) - (i-1));
	return 0;
}