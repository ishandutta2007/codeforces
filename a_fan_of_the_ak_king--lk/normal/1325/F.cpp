#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=10005;
typedef long double lb;
int n,m,head[N],Next[N*4],adj[N*4],k,vis[N],i,j,u,v,dep[N],t,fa[N];
vector<int>g[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i)
{
	int j;
	vis[i]=1;
	g[dep[i]%(t-1)].push_back(i);
	for(j=head[i];j;j=Next[j])
		if(!vis[adj[j]])
		{
			dep[adj[j]]=dep[i]+1;
			fa[adj[j]]=i;
			dfs(adj[j]);
		}
		else
			if(dep[i]-dep[adj[j]]+1>=t)
			{
				puts("2");
				printf("%d\n",dep[i]-dep[adj[j]]+1);
				for(k=i;k!=adj[j];k=fa[k])
					printf("%d ",k);
				printf("%d ",adj[j]);
				exit(0);
			}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	for(i=1;i*i<n;++i);
	t=i;
	dfs(1);
	puts("1");
	for(i=0;i<n;++i)
		if(g[i].size()>=t)
		{
			for(j=0;j<t;++j)
				printf("%d ",g[i][j]);
			return 0;
		}
}