#include <stdio.h>

int
main(void)
{
	int n, k, p=0, np=0, a;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if(a&1)
			np++;
		else
			p++;
	}
	if(n == k)
	{
		if(np % 2 == 1)
			printf("Stannis\n");
		else
			printf("Daenerys\n");
	}
	else if((n % 2) == 1 && (k % 2) == 1)
	{
		if(np - ((n-k)/2) + 1 >= k+1)
			printf("Stannis\n");
		else
			printf("Daenerys\n");
	}
	else if(n % 2 == 0 && (k % 2) == 1)
	{
		if(p - ((n-k)/2) >= k + 1)
			printf("Daenerys\n");
		else
			printf("Stannis\n");
	}
	else if(n % 2 == 0 && (k % 2) == 0)
	{
		printf("Daenerys\n");
	}
	else if(n % 2 == 1 && k % 2 == 0)
	{
		if(p - ((n-k)/2) >= k + 1 || np - ((n-k)/2) >= k + 1 )
			printf("Daenerys\n");
		else
			printf("Stannis\n");
	}
}