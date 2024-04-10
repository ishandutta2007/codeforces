#include <stdio.h>

int
main(void)
{
	int n, i, m, x, y ,neg = 0, pos = 0;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(x > 0) pos++;
		else	neg++;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		x = (y-x) + 1;
		if(x % 2 == 0 && x / 2 <= pos && x/2 <= neg)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}