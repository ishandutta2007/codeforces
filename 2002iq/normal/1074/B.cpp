#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[1005];
bool vis[1005],vis2[1005];
int dfs(int node,int p,int tar)
{
	if (node==tar)
	return 0;
	for (int u:v[node])
	{
		if (u!=p)
		{
			int tmp=dfs(u,node,tar);
			if (!tmp)
			{
				if (vis[node])
				return node;
				return 0;
			}
			else if (tmp!=-1)
			return tmp;
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k1,k2,r1,r2;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		v[i].clear();
		for (int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		scanf("%d",&k1);
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		for (int i=0;i<k1;i++)
		{
			int a;
			scanf("%d",&a);
			vis[a]=1;
			r1=a;
		}
		scanf("%d",&k2);
		for (int i=0;i<k2;i++)
		{
			int a;
			scanf("%d",&a);
			vis2[a]=1;
			r2=a;
		}
		printf("B %d\n",r2);
		fflush(stdout);
		int tmp;
		scanf("%d",&tmp);
		if (vis[tmp])
		{
			printf("C %d\n",tmp);
			fflush(stdout);
			continue;
		}
		tmp=dfs(r1,0,tmp);
		printf("A %d\n",tmp);
		fflush(stdout);
		int o;
		scanf("%d",&o);
		if (!vis2[o])
		tmp=-1;
		printf("C %d\n",tmp);
		fflush(stdout);
	}
}