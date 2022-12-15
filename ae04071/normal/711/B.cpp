#include <cstdio>

long long arr[510][510];
long long row_sum[510];
long long col_sum[510];
int n;
int y, x;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%I64d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				y = i;
				x = j;
			}
		}
	}
	
	if (n == 1)
	{
		if (arr[0][0] == 0)
		{
			printf("1\n");
		}
		else
			printf("-1\n");

		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			row_sum[i] += arr[i][j];
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			col_sum[j] += arr[i][j];
		}
	}

	long long dia_sum = 0, india_sum = 0;
	for (int i = 0; i < n; i++)
	{
		dia_sum += arr[i][i];
		india_sum += arr[i][n - i - 1];
	}

	long long sum = (y == 0) ? row_sum[1] : row_sum[0];
	for (int i = 0; i < n; i++)
	{
		if (sum != row_sum[i] && i != y)
		{
			printf("-1\n");
			
			return 0;
		}
		if (sum != col_sum[i] && i != x)
		{
			printf("-1\n");
			
			return 0;
		}
	}
	if (sum != dia_sum && (y != x))
	{
		printf("-1\n");

		return 0;
	}
	if (sum != india_sum && (y != (n - x - 1)))
	{
		printf("-1\n");

		return 0;
	}

	if (row_sum[y] != col_sum[x])
	{
		printf("-1\n");
		
		return 0;
	}
	if (y == x)
	{
		if (row_sum[y] != dia_sum)
		{
			printf("-1\n");
			
			return 0;
		}
	}
	if (y == (n - x - 1))
	{
		if (row_sum[y] != india_sum)
		{
			printf("-1\n");
			
			return 0;
		}
	}

	long long res = sum - row_sum[y];
	if (res <= 0) printf("-1\n");
	else printf("%I64d\n", sum - row_sum[y]);

	return 0;
}