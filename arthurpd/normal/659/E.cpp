//http://codeforces.com/contest/659/problem/E
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[112345];
int deg[112345];

int
main(void)
{
	queue<int> q;
	int n, m, a, b, ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		deg[a]++, deg[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
		if(deg[i] == 0)
			ans++;
		else if(deg[i] == 1)
			q.push(i);

	while(!q.empty())
	{
		a = q.front();
		q.pop();
		if(deg[a] == 0)
		{
			ans++;
			continue;
		}
		for(int i = 0; i < graph[a].size(); i++)
			if(--deg[graph[a][i]] == 1)
				q.push(graph[a][i]);
	}
	printf("%d\n", ans);
}