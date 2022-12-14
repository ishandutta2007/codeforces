#include<cstdio>
#include<iostream>
using namespace std;
struct Edge{
	int to,next;
}e[202020];
int head[101010],cnt=0;
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int anc[20][101010];
int dep[101010];
void dfs(int x,int fa)
{
	for(int i=head[x];i!=0;i=e[i].next)
	{
		int to=e[i].to;
		if(to!=fa)
		{
			dep[to]=dep[x]+1;
			anc[0][to]=x;
			dfs(to,x);
		}
	}
}

int lca(int u,int v)
{
	if(u==v)
		return u;
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=18;i>=0&&dep[u]!=dep[v];i--)
	if(dep[anc[i][u]]>=dep[v])
		u=anc[i][u];
	if(u==v)
		return u;
	for(int i=18;i>=0;i--)
	if(anc[i][u]!=anc[i][v])
	{
		u=anc[i][u];
		v=anc[i][v];
	}
	return anc[0][u];
}
int dis(int u,int v)
{
	int LCA=lca(u,v);
	return dep[u]+dep[v]-dep[LCA]-dep[LCA];
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		add(i,p);
		add(p,i);
	}
	anc[0][1]=1;
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=18;i++)
	for(int j=1;j<=n;j++)
		anc[i][j]=anc[i-1][anc[i-1][j]];
	while(q--)
	{
		int s,t,f;
		scanf("%d%d%d",&s,&t,&f);
		int mid=1;
		int might;
		might=lca(s,t);
		if(dep[might]>dep[mid])
			mid=might;
		might=lca(s,f);
		if(dep[might]>dep[mid])
			mid=might;
		might=lca(t,f);
		if(dep[might]>dep[mid])
			mid=might;
		int ans=0;
		ans=max(dis(mid,s),max(dis(mid,t),dis(mid,f)));
		printf("%d\n",ans+1);
	}
	return 0;
}