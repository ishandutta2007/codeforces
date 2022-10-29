#include <bits/stdc++.h>
using namespace std;
bool vis[1000005],col[1000005];
int x[500005],y[500005];
vector<int> v[1000005],cyc;
void dfs(int node,bool c)
{
	col[node]=c;
	vis[node]=1;
	for (int u:v[node])
	{
		if (!vis[u])
		dfs(u,(c^1));
	}
}
void dfs2(int node)
{
	cyc.push_back(node);
	vis[node]=1;
	for (int u:v[node])
	{
		if (!vis[u])
		dfs2(u);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	if (n%2)
	{
		puts("Second");
		fflush(stdout);
		for (int i=1;i<=2*n;i++)
		{
			int a;
			scanf("%d",&a);
			if (!x[a])
			x[a]=i;
			else
			y[a]=i;
		}
		for (int i=1;i<=n;i++)
		{
			v[x[i]].push_back(y[i]);
			v[y[i]].push_back(x[i]);
			v[i].push_back(i+n);
			v[i+n].push_back(i);
		}
		for (int i=1;i<=2*n;i++)
		{
			if (!vis[i])
			dfs(i,0);
		}
		int cur=0;
		for (int i=1;i<=2*n;i++)
		{
			if (col[i])
			cur=(cur+i)%(2*n);
		}
		if (cur)
		{
			memset(vis,0,sizeof(vis));
			for (int i=1;i<=2*n;i++)
			{
				if (!vis[i])
				{
					cyc.clear();
					dfs2(i);
					if (cyc.size()%4)
					{
						for (int j:cyc)
						col[j]^=1;
						break;
					}
				}
			}
		}
		for (int i=1;i<=2*n;i++)
		{
			if (col[i])
			printf("%d ",i);
		}
	}
	else
	{
		puts("First");
		fflush(stdout);
		for (int i=1;i<=n;i++)
		printf("%d ",i);
		for (int i=1;i<=n;i++)
		printf("%d ",i);
	}
	printf("\n");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
}