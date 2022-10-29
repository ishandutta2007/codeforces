#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

vector<int> graph[3123];
int d[3123][3123];

void bfs(int a)
{
	queue<int> q;
	memset(d[a], 0x3f, sizeof(d[a]));
	d[a][a] = 0;
	q.push(a);
	while(!q.empty())
	{
		int b = q.front();
		q.pop();
		for(int i = 0; i < graph[b].size(); i++)
			if(d[a][graph[b][i]] == 0x3f3f3f3f)
			{
				q.push(graph[b][i]);
				d[a][graph[b][i]] = d[a][b] + 1;
			}
	}
}

int
main(void)
{
	int n, m, a, b, e, f, x, y;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
		bfs(i);
	scanf("%d %d %d", &a, &b, &x);
	scanf("%d %d %d", &e, &f, &y);
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(d[a][i] + d[i][j] + d[j][b] <= x && d[e][i] + d[i][j] + d[j][f] <= y)
				ans = min(ans, d[a][i] + d[e][i] + d[i][j] + d[j][b] + d[j][f]);
			if(d[a][i] + d[i][j] + d[j][b] <= x && d[f][i] + d[i][j] + d[j][e] <= y)
				ans = min(ans, d[a][i] + d[f][i] + d[i][j] + d[j][b] + d[j][e]);
		}
	if(d[a][b] <= x && d[e][f] <= y)
		ans = min(ans, d[a][b] + d[e][f]);
	
	if(ans != 0x3f3f3f3f)
		printf("%d\n", m - ans);
	else
		printf("-1\n");
}