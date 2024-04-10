#include <bits/stdc++.h>
using namespace std;
int val[510][510][2];
inline void addedge(int a, int b, int c, int d)
{
	if(a + b > c + d)
		swap(a, c), swap(b, d);
	if(d > b)
		val[a - 1][b][0]++;
	else
		val[a][b - 1][1]++;
}
priority_queue < pair< int, pair<int, int> > > q;
int dis[510][510], vis[510][510];
inline void upd(int x, int y, int xx, int yy, int v)
{
	if(vis[xx][yy])
		return;
	if(dis[x][y] + v < dis[xx][yy])
	{
		dis[xx][yy] = dis[x][y] + v;
		q.push({-dis[xx][yy], {xx, yy}});
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 0; i <= k; i++)
			for(int j = 0; j <= k; j++)
				val[i][j][0] = val[i][j][1] = 0;
		for(int i = 1; i <= n; i++)
		{
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			addedge(a, b, c, d);
			addedge(k + 1 - a, k + 1 - b, k + 1 - c, k + 1 - d);
		}
		for(int i = 0; i <= k; i++)
			for(int j = 0; j <= k; j++)
				dis[i][j] = INT_MAX >> 1, vis[i][j] = false;
		while(!q.empty())
			q.pop();
		for(int i = 0; i <= k; i++)
		{
			dis[i][0] = dis[0][i] = dis[i][k] = dis[k][i] = 0;
			q.push({0, {i, 0}}), q.push({0, {i, k}});
			if(i > 0 && i < k)
				q.push({0, {0, i}}), q.push({0, {k, i}});
		}
		int t = k >> 1;
		while(!vis[t][t])
		{
			auto tmp = q.top();
			q.pop();
			int x = tmp.second.first, y = tmp.second.second;
			if(vis[x][y])
				continue;
			vis[x][y] = true;
			if(x < k)
				upd(x, y, x + 1, y, val[x][y][0]);
			if(y < k)
				upd(x, y, x, y + 1, val[x][y][1]);
			if(x > 0)
				upd(x, y, x - 1, y, val[x - 1][y][0]);
			if(y > 0)
				upd(x, y, x, y - 1, val[x][y - 1][1]);
		}
		printf("%d\n", n - dis[t][t]);
	}
	return 0;
}