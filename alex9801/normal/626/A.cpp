#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[210];

int main()
{
	int n, x, y, r = 0, i, j, k;
	scanf("%d%s", &n, arr);
	for(i = 0; i<n; i++)
	{
		for(j = i; j<n; j++)
		{
			x = 0; y = 0;
			for(k = i; k<=j; k++)
			{
				if(arr[k]=='U')
					x++;
				if(arr[k]=='D')
					x--;
				if(arr[k]=='R')
					y++;
				if(arr[k]=='L')
					y--;
			}
			if(x==0&&y==0)
				r++;
		}
	}

	printf("%d", r);
	return 0;
}