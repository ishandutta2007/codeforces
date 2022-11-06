#include <stdio.h>
#include <string.h>
#include <algorithm>

bool chk[100010];

int main()
{
	int n, i, j;
	scanf("%d", &n);

	if(n <= 2)
		printf("1\n");
	else
		printf("2\n");

	for(i = 2; i<=n+1; i++)
	{
		if(!chk[i])
		{
			printf("1 ");
			for(j = i; j<=n+1; j += i)
				chk[j] = 1;
		}
		else
			printf("2 ");
	}

	return 0;
}