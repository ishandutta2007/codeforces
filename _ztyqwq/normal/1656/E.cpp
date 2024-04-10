#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[200010];
int ecnt = 0, head[100010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
const int X = 1, Y = -1;
int ans[100010];
void dfs(int u, int fa, bool t)
{
	int cnt = 0;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa)
			continue;
		dfs(v, u, t ^ 1);
		cnt++;
	}
	if(t)
		ans[u] = X - cnt * Y;
	else
		ans[u] = Y - cnt * X;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			head[i] = -1;
		ecnt = 0;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v), addedge(v, u);
		}
		dfs(1, 1, true);
		ans[1] += Y;
		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}