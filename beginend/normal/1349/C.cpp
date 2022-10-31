#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef long long LL;

const int N = 1005;

int n, m, q, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dis[N][N], a[N][N];
bool vis[N][N];
queue<pi> que;
char str[N];

void bfs()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (vis[i][j]) que.push(make_pair(i, j));
	while (!que.empty())
	{
		int x = que.front().first, y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int p = x + dx[i], q = y + dy[i];
			if (p < 1 || p > n || q < 1 || q > m || vis[p][q] || dis[p][q]) continue;
			dis[p][q] = dis[x][y] + 1;
			que.push(make_pair(p, q));
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++)
			a[i][j] = str[j] - '0';
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 4; k++)
			{
				int p = i + dx[k], q = j + dy[k];
				if (p < 1 || p > n || q < 1 || q > m || a[i][j] != a[p][q]) continue;
				vis[i][j] = 1;
				break;
			}
	bfs();
	while (q--)
	{
		int i, j; LL p; scanf("%d%d%lld", &i, &j, &p);
		if (vis[i][j]) printf("%d\n", p % 2 == 0 ? a[i][j] : 1 - a[i][j]);
		else if (!dis[i][j]) printf("%d\n", a[i][j]);
		else if (p <= dis[i][j]) printf("%d\n", a[i][j]);
		else printf("%d\n", (p - (LL)dis[i][j]) % 2 == 0 ? a[i][j] : 1 - a[i][j]);
	}
	return 0;
}