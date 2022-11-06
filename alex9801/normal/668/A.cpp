#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[100][100];
int res[100][100];

int main()
{
	int n, m, q, t, r, c, x, u, i, j, k;
	scanf("%d%d%d", &n, &m, &q);

	for(i = 0; i<n; i++)
		for(j = 0; j<m; j++)
			arr[i][j] = i*m+j;

	for(i = 0; i<q; i++)
	{
		scanf("%d", &t);

		if(t==1)
		{
			scanf("%d", &r);
			r--;

			u = arr[r][0];
			for(j = 0; j<m-1; j++)
				arr[r][j] = arr[r][j+1];
			arr[r][m-1] = u;
		}
		else if(t==2)
		{
			scanf("%d", &c);
			c--;

			u = arr[0][c];
			for(j = 0; j<n-1; j++)
				arr[j][c] = arr[j+1][c];
			arr[n-1][c] = u;
		}
		else if(t==3)
		{
			scanf("%d%d%d", &r, &c, &x);
			r--;
			c--;

			res[arr[r][c]/m][arr[r][c]%m] = x;
		}
	}

	for(i = 0; i<n; i++)
	{
		for(j = 0; j<m; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}