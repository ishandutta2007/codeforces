#include <bits/stdc++.h>
using namespace std;
int a[101];
int ans[501][501];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		map<int, int> r, c;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				int x;
				scanf("%d", &x);
				c[x] = j;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				int x;
				scanf("%d", &x);
				r[x] = j;
				ans[r[x]][c[x]] = x;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				printf("%d ", ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}