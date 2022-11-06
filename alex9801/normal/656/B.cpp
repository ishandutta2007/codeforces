#include <stdio.h>
#include <algorithm>

int m[16];
int r[16];

int main()
{
	int n, c = 0, i, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", &m[i]);
	for(i = 0; i<n; i++)
		scanf("%d", &r[i]);

	for(i = 0; i<720720; i++)
	{
		for(j = 0; j<n; j++)
		{
			if(i%m[j] == r[j])
			{
				c++;
				break;
			}
		}
	}

	printf("%.6lf", c/720720.0);
	return 0;
}