#include<bits/stdc++.h>
using namespace std;
int n,fa[200005],a[200005],b[200005],d[200005];
int e[200005],f[200005],ff[200005],A[200005],cnt=0;
vector<int>g[200005],p[200005];
void dfs(int x,int la)
{
	d[x]=e[x]=++cnt;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		fa[cu]=x;
		dfs(cu,x);
		e[x]=max(e[x],e[cu]);
	}
}
bool Dx(int x)
{
	int tt=lower_bound(b+1,b+n+1,a[x])-b;
	int wz=lower_bound(p[tt].begin(),p[tt].end(),d[x]+1)-p[tt].begin();
	if(p[tt][wz]<=e[x])return 1;
	return 0;
}
bool DDx(int x,int dd,int ee)
{
	int tt=lower_bound(b+1,b+n+1,a[x])-b;
	int wz=lower_bound(p[tt].begin(),p[tt].end(),dd)-p[tt].begin();
	int zw=lower_bound(p[tt].begin(),p[tt].end(),ee+1)-p[tt].begin();
	if(zw<p[tt].size()-1)return 1;
	if(dd==d[x]&&wz>1)return 1;
	if(dd!=d[x]&&wz>2)return 1;
	return 0;
}
void dfs1(int x,int la)
{
	if(la&&g[x].size()==1)
	{
		f[x]=1;
		return;
	}
	if(Dx(x));
	else f[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs1(cu,x);
		f[x]&=f[cu];
		A[x]+=f[cu];
	}
}
void dfs2(int x,int la)
{
	if(!fa[x])ff[x]=1;
	else if(DDx(x,d[x],e[x])||DDx(fa[x],d[x],e[x])||!ff[fa[x]]);
	else if(A[fa[x]]-f[x]!=g[fa[x]].size()-(!!fa[fa[x]])-1);
	else ff[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		dfs2(cu,x);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)p[lower_bound(b+1,b+n+1,a[i])-b].push_back(d[i]);
	for(int i=1;i<=n;i++)p[i].push_back(0),p[i].push_back(n+1);
	for(int i=1;i<=n;i++)sort(p[i].begin(),p[i].end());
	dfs1(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)ans+=(f[i]&ff[i]);
	cout<<ans<<endl;
	return 0;
}