#include <stdio.h>

int BIT[112345], n, m;

void add(int idx, int v)
{
 	 for(int i = idx; i < 112345; i += -i&i)
	 		 BIT[i] += v;
}

int sum(int idx)
{
 	int retv = 0;
	for(int i = idx; i > 0; i -= -i&i)
		retv += BIT[i];
	return retv;
}

int
main(void)
{
 	int c,c2;
	for(c = getchar(); c2 != '\n'; c = c2, n++)
		  if((c2 = getchar()) == c)
		  		 add(n+1, 1);
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
	 	scanf("%d %d", &c, &c2);
		printf("%d\n", sum(c2-1) - sum(c-1));
	}

 	return 0;
}