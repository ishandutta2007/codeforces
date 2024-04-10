#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

std::vector<int> arr[100001];
std::vector<int> res[3];
int col[100001];

bool f(int x, int c)
{
	int t = 3-c;
	col[x] = c;
	res[c].push_back(x);
	for(int y : arr[x])
	{
		if(col[y]==c)
			return 0;
		if(col[y]==0)
		{
			if(!f(y, t))
				return 0;
		}
	}
	return 1;
}

int main()
{
	int n, m, x, y, i, j;
	scanf("%d%d", &n, &m);
	for(i = 0; i<m; i++)
	{
		scanf("%d%d", &x, &y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	for(i = 1; i<=n; i++)
	{
		if(col[i]==0)
		{
			if(!f(i, 1))
			{
				printf("-1");
				return 0;
			}
		}
	}

	for(i = 1; i<=2; i++)
	{
		printf("%d\n", res[i].size());
		for(j = 0; j<res[i].size(); j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}


	return 0;
}