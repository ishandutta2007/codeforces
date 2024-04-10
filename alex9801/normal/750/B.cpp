#include <stdio.h>
#include <string.h>
#include <algorithm>

char tmp[100];

int main()
{
	int n, d, x, i;
	scanf("%d", &n);
	x = 0;
	for(i = 0; i<n; i++)
	{
		scanf("%d%s", &d, tmp);

		if(x==0 && tmp[0] != 'S')
		{
			printf("NO");
			return 0;
		}

		if(x==20000 && tmp[0] != 'N')
		{
			printf("NO");
			return 0;
		}

		if(tmp[0] == 'N' && x+d > 40000)
		{
			printf("NO");
			return 0;
		}

		if(tmp[0] == 'S' && (x > 20000 && x-d <20000 || x < 20000 && x-d <-20000))
		{
			printf("NO");
			return 0;
		}

		if(tmp[0] == 'N')
			x += d;
		else if(tmp[0] == 'S')
			x -= d;

		x = (x%40000 + 40000) % 40000;

		
	}

	if(x == 0)
		printf("YES");
	else
		printf("NO");

	return 0;
}