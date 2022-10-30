#include <bits/stdc++.h>
using namespace std;
int n;
int g[2010][2010];
int a[2010];
inline void work(int x, int y, int &xx, int &yy, int &val)
{
	if((x ^ y) & 1)
	{
		if(y > x)
			xx = 1, yy = y - x + 1, val = (x - 1) & 1;
		else
			xx = 1, yy = x - y, val = (y - 1) & 1;
	}
	else
	{
		if(x + y <= n)
			xx = 1, yy = x + y - 1, val = (x - 1) & 1;
		else
			xx = 1, yy = n * 2 - x - y + 2, val = (n - y) & 1;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for(int j = 1; j <= n; j++)
			if(s[j - 1] == 'G')
				g[i][j] = 1;
			else if(s[j - 1] == 'S')
				g[i][j] = 2;
	}
	if(n & 1)
	{
		printf("NONE\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!g[i][j])
				continue;
			int xx, yy, val;
			work(i, j, xx, yy, val);
			int res = (val ? 3 - g[i][j] : g[i][j]);
			if(a[yy] != 0 && a[yy] != res)
			{
				printf("NONE\n");
				return 0;
			}
			a[yy] = res;
			a[((yy - 1) ^ 1) + 1] = res;
		}
	for(int i = 1; i <= n; i++)
		if(!a[i])
		{
			printf("MULTIPLE\n");
			return 0;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			int xx, yy, val;
			work(i, j, xx, yy, val);
			int res = (val ? 3 - a[yy] : a[yy]);
			g[i][j] = res;
		}
	printf("UNIQUE\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			putchar(g[i][j] == 1 ? 'G' : 'S');
		putchar('\n');
	}
	return 0;
}