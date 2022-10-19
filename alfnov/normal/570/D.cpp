#include<bits/stdc++.h>
using namespace std;
vector<int>g[500005];
char c[500005];
int fa[500005],dep[500005],sz[500005],an[500005];
int bg[500005],en[500005],dy[500005],tot;
int L[26][500005];
vector<pair<int,int> >xq[500005];
void dfs1(int x)
{
	bg[x]=en[x]=++tot;
	dy[bg[x]]=x,sz[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		dep[cu]=dep[x]+1;
		dfs1(cu);
		en[x]=en[cu];
		sz[x]+=sz[cu];
	}
}
void dfs2(int x,int sv)
{
	int ans=-1,W=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(ans<sz[cu])ans=sz[cu],W=cu;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu!=W)dfs2(cu,0);
	}
	if(W)dfs2(W,1);
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu!=W)for(int j=bg[cu];j<=en[cu];j++)
			L[c[dy[j]]-'a'][dep[dy[j]]]++;
	}
	L[c[x]-'a'][dep[x]]++;
	for(int i=0;i<xq[x].size();i++)
	{
		int h=xq[x][i].second,b=xq[x][i].first,cc=0;
		for(int j=0;j<26;j++)cc+=(L[j][h]&1);
		if(cc<=1)an[b]=1;
		else an[b]=0;
	}
	if(!sv)for(int i=bg[x];i<=en[x];i++)
		L[c[dy[i]]-'a'][dep[dy[i]]]--;
}
int main()
{
	int n,m;
	cin>>n>>m;
	fa[1]=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		g[fa[i]].push_back(i);
	}
	dep[1]=1,tot=0,dfs1(1);
	scanf("%s",c+1);
	for(int i=1;i<=m;i++)
	{
		int x,h;
		scanf("%d%d",&x,&h);
		xq[x].push_back(make_pair(i,h));
	}
	dfs2(1,0);
	for(int i=1;i<=m;i++)
	{
		if(an[i])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}