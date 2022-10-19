#include<bits/stdc++.h>
using namespace std;
long long an[100005],na;
int sz[100005],cnt[100005],c[100005],bg[100005],en[100005],gb[100005];
int lx,tot;
vector<int>g[100005];
void dfs1(int x,int la)
{
	bg[x]=en[x]=++tot,sz[x]=1,gb[bg[x]]=x;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs1(cu,x);
		en[x]=en[cu],sz[x]+=sz[cu];
	}
}
void add(int x)
{
	cnt[c[x]]++;
	if(cnt[c[x]]>lx)lx=cnt[c[x]],na=c[x];
	else if(cnt[c[x]]==lx)na+=c[x];
}
void dfs2(int x,int la,int gs)
{
	int ans=0,w=-1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		if(ans<sz[cu])ans=sz[cu],w=cu;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la||cu==w)continue;
		dfs2(cu,x,0);
	}
	if(w!=-1)dfs2(w,x,1);
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la||cu==w)continue;
		for(int j=bg[cu];j<=en[cu];j++)add(gb[j]);
	}
	add(x);
	an[x]=na;
	if(!gs)
	{
		lx=na=0;
		for(int i=bg[x];i<=en[x];i++)cnt[c[gb[i]]]=0;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tot=0,dfs1(1,0);
	lx=na=0,dfs2(1,0,0);
	for(int i=1;i<=n;i++)printf("%lld ",an[i]);
	return 0;
}