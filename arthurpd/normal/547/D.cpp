#include <stdio.h>
#include <vector>
using namespace std;

vector<int> graph[412345];
vector<int> p[412345];
int ans[412345];
bool been[412345];
bool used[812345];

void dfs(int a, int c)
{
	been[a] = true;
	while(!graph[a].empty())
		if(!used[p[a].back()])
		{
			ans[p[a].back()] = c;
			used[p[a].back()] = true;
			int tmp = graph[a].back();
			graph[a].pop_back();
			p[a].pop_back();
			dfs(tmp, c ^ 1);
		}
		else
		{
			p[a].pop_back();
			graph[a].pop_back();
		}
}

int
main(void)
{
	int n, a, b;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		a--, b--;
		graph[2*a].push_back(2*b+1);
		graph[2*b+1].push_back(2*a);
		p[2*a].push_back(i);
		p[2*b+1].push_back(i);
	}
	int id = n+1;
	for(int i = 0; i < 400000; i++)
		if(graph[i].size() & 1)
		{
			graph[i].push_back(400000 + (i&1));
			graph[400000 + (i&1)].push_back(i);
			p[i].push_back(id);
			p[400000 + (i&1)].push_back(id++);
		}
	if(graph[400000].size() & 1)
	{
		graph[400000].push_back(400001);
		graph[400001].push_back(400000);
		p[400000].push_back(400001);
		p[400001].push_back(400000);
	}
	for(int i = 0; i < 400000; i++)
		if(!been[i])
			dfs(i, 0);
	for(int i = 1; i <= n; i++)
		printf("%c", ans[i] ? 'r' : 'b');
	printf("\n");
}