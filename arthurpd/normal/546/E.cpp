//http://codeforces.com/problemset/problem/546/E
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int a[1123], b[1123];

struct edge{
	int dest, cap, re;
	edge(int x, int y, int z) : dest(x), cap(y), re(z){}
};

vector<edge> graph[1123];

void put_edge(int u, int v, int cap)
{
	graph[u].push_back(edge(v, cap, graph[v].size()));
	graph[v].push_back(edge(u, 0, graph[u].size() - 1));
}

bool in[1123];
int p[1123];
int e_used[1123];

int bfs(int s, int t)
{
	queue<int> q;
	q.push(s);
	memset(in, 0, sizeof(in));
	in[s] = true;
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		if(a == t)
			return true;
		for(int i = 0; i < graph[a].size(); i++)
			if(graph[a][i].cap > 0 && !in[graph[a][i].dest])
			{
				q.push(graph[a][i].dest);
				in[graph[a][i].dest] = true;
				p[graph[a][i].dest] = a;
				e_used[graph[a][i].dest] = i;
			}
	}
	return false;
}

int flow(int s, int t)
{
	int retv = 0;
	while(bfs(s, t))
	{
		int x = 0x3f3f3f3f;
		for(int i = t; i != s; i = p[i])
			x = min(x, graph[p[i]][e_used[i]].cap);
		for(int i = t; i != s; i = p[i])
			graph[p[i]][e_used[i]].cap -= x, graph[i][graph[p[i]][e_used[i]].re].cap += x;
		retv += x;
	}
	return retv;
}

int ans[1123][1123];

int main(void)
{
	int n, m, u, v, expectedB = 0, expectedA = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; expectedB += b[i], expectedA += a[i], i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
	{
		put_edge(0, 2*i, a[i]);
		put_edge(2*i, 1, b[i]);
		put_edge(2*i, 2*i + 1, a[i]);
	}

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		put_edge(2*u + 1, 2*v, a[u]);
		put_edge(2*v + 1, 2*u, a[v]);
	}

	if(flow(0, 1) == expectedA && expectedA == expectedB)
	{
		printf("YES\n");
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < graph[2*i + 1].size(); j++)
				ans[i][graph[2*i + 1][j].dest / 2] += a[i] - graph[2*i + 1][j].cap;
		for(int i = 1; i <= n; printf("\n"), i++)
		{
			printf("%d", ans[i][1]);
			for(int j = 2; j <= n; j++)
				printf(" %d", ans[i][j]);
		}
	}
	else
	{
		printf("NO\n");
	}

}