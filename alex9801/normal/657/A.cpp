#include <stdio.h>
#include <algorithm>

int main()
{
	int n, d, h, i;
	scanf("%d%d%d", &n, &d, &h);

	if(h>d || d>2*h || n<h+1 || n<d+1)
	{
		printf("-1");
		return 0;
	}

	if(d==1)
	{
		if(h==1 && n==2)
			printf("1 2");
		else
			printf("-1");
		return 0;
	}

	for(i = 2; i<=h+1; i++)
		printf("%d %d\n", i-1, i);

	if(h==d)
	{
		for(i = h+2; i<=n; i++)
			printf("%d %d\n", 2, i);
		return 0;
	}

	for(i = h+2; i<=d+1; i++)
	{
		if(i==h+2)
			printf("%d %d\n", 1, i);
		else
			printf("%d %d\n", i-1, i);
	}

	for(i = d+2; i<=n; i++)
		printf("%d %d\n", 1, i);

	return 0;
}