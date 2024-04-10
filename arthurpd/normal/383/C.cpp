#include <stdio.h>
#include <vector>
using namespace std;

int id[2] = {1, 1};
int v[2][212345], in[212345], l[212345];
vector<int> graph[212345];
int bit[2][212345];
int ex[2][212345];

void change(int bit[], int pos, int x)
{
	for(int i = pos; i > 0; i -= -i&i)
		bit[i] += x;
}

int get(int bit[],int pos)
{
	int retv = 0;
	for(int i = pos; i < 112345; i += -i&i)
		retv += bit[i];
	return retv;
}

void dfs(int a, int h, int p)
{
	l[a] = h;
	v[h&1][a] = id[h&1]++;
	v[(h&1)^1][a] = id[(h&1)^1];
	change(bit[h&1],v[h&1][a], in[a]), change(bit[h&1], v[h&1][a] - 1, -in[a]);
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != p)
			dfs(graph[a][i], h+1, a);
	ex[h&1][a] = id[h&1] - 1;
	ex[(h&1)^1][a] = id[(h&1)^1] - 1;
}

int
main(void)
{
	int n, m, x, y, tp;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &in[i]);
	for(int i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1, 0, 1);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &tp);
		if(tp == 1)
		{
			scanf("%d %d", &x, &y);
			change(bit[l[x]&1], ex[l[x]&1][x], y), change(bit[l[x]&1], v[l[x]&1][x] - 1, -y);
			change(bit[(l[x]&1)^1], ex[(l[x]&1)^1][x], -y), change(bit[(l[x]&1)^1], v[(l[x]&1)^1][x] - 1, y);
//			change(ex[x], -y), change(v[x], y);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", get(bit[l[x]&1], v[l[x]&1][x]));
		}
	}
}