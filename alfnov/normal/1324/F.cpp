#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005],d[200005];
vector<int>g[200005];
void dfs1(int x,int la)
{
	f[x]=a[x]*2-1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs1(cu,x);
		f[x]+=max(f[cu],0);
	}
}
void dfs2(int x,int la)
{
	int he=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		he+=max(0,f[cu]);
	}
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		d[cu]=max(0,d[x]+he-max(0,f[cu])+(2*a[x]-1));
		dfs2(cu,x);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%d ",f[i]+d[i]);
	return 0;
}