#include <bits/stdc++.h>
using namespace std;
char g[510][510];
int n, m;
inline int Hash(int x, int y)
{
	return (x - 1) * m + y;
}
struct Edge
{
	int to, nxt;
}e[1000010];
int head[250010], ecnt = 0;
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
inline void connect(int x, int y)
{
	addedge(x, y), addedge(y, x);
}
int ans[510][510];
void dfs(int x, int y, int val)
{
	ans[x][y] = val;
	int u = Hash(x, y);
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		int xx = (v - 1) / m + 1, yy = (v - 1) % m + 1;
		if(!ans[xx][yy])
			dfs(xx, yy, 5 - val);
	}
}
int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", g[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(g[i][j] != 'X')
				continue;
			int tot = (g[i + 1][j] == '.') + (g[i - 1][j] == '.') + (g[i][j + 1] == '.') + (g[i][j - 1] == '.');
			if(tot & 1)
			{
				printf("NO\n");
				return 0;
			}
			if((g[i + 1][j] == '.' && g[i - 1][j] == '.' && g[i][j + 1] == 'X' && g[i][j - 1] == 'X')
			|| (g[i + 1][j] == 'X' && g[i - 1][j] == 'X' && g[i][j + 1] == '.' && g[i][j - 1] == '.'))
			{
				connect(Hash(i + 1, j), Hash(i - 1, j));
				connect(Hash(i, j + 1), Hash(i, j - 1));
			}
			else
			{
				if(g[i + 1][j] == '.' && g[i][j + 1] == '.')
					connect(Hash(i + 1, j), Hash(i, j + 1));
				if(g[i - 1][j] == '.' && g[i][j + 1] == '.')
					connect(Hash(i - 1, j), Hash(i, j + 1));
				if(g[i + 1][j] == '.' && g[i][j - 1] == '.')
					connect(Hash(i + 1, j), Hash(i, j - 1));
				if(g[i - 1][j] == '.' && g[i][j - 1] == '.')
					connect(Hash(i - 1, j), Hash(i, j - 1));
			}
		}
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(g[i][j] == '.' && !ans[i][j])
				dfs(i, j, 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(g[i][j] == 'X')
				ans[i][j] = ans[i + 1][j] * (g[i + 1][j] == '.')
				+ ans[i - 1][j] * (g[i - 1][j] == '.')
				+ ans[i][j + 1] * (g[i][j + 1] == '.')
				+ ans[i][j - 1] * (g[i][j - 1] == '.');
	printf("YES\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			printf("%d ", ans[i][j]);
		putchar('\n');
	}
	return 0;
}