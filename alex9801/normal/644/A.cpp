#include <stdio.h>

int arr[100][100];

int main()
{
	int n, a, b, c = 1, i, j;
	scanf("%d%d%d", &n, &a, &b);

	for(i = 0; i<a&&c<=n; i++)
	{
		for(j = 0; j<b&&c<=n; j++)
			arr[i][j] = c++;
		i++;
		if(i<a)
			for(j = b-1; j>=0&&c<=n; j--)
				arr[i][j] = c++;
	}

	if(c<=n)
	{
		printf("-1");
		return 0;
	}
	for(i = 0; i<a; i++)
	{
		for(j = 0; j<b; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}