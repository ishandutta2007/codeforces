#include <stdio.h>

bool arr[510][510];
char res[510];
int n;

void f(int x)
{
	int i;
	for(i = 1; i<=n; i++)
	{
		if(i==x)
			continue;
		if(!arr[i][x])
		{
			if(res[i]=='a')
				res[x] = 'c';
			else
				res[x] = 'a';
			if(res[i]=='b')
				f(i);
			return;
		}
	}
}

int main()
{
	int m, a, b, i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i<=m; i++)
	{
		scanf("%d%d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for(i = 1; i<=n; i++)
		res[i] = 'b';

	for(i = 1; i<=n; i++)
		if(res[i]=='b')
			f(i);

	for(i = 1; i<n; i++)
	{
		for(j = i+1; j<=n; j++)
		{
			if(res[i]=='a'&&res[j]=='c'||res[i]=='c'&&res[j]=='a')
			{
				if(arr[i][j])
				{
					printf("No");
					return 0;
				}
			}
			else
			{
				if(!arr[i][j])
				{
					printf("No");
					return 0;
				}
			}
		}
	}

	printf("Yes\n%s", res+1);

	return 0;
}