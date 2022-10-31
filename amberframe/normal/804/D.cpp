#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;
typedef long double cdb;
typedef pair<int,int> mp;
const int maxn = 300005;
#define pb push_back

int ehead[maxn],ecnt;
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v)
{
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

int n,m,q,g[maxn],bl[maxn],w[maxn];
int gu,gv,gd,f[maxn],fu[maxn],sz[maxn];
vector<int> s[maxn];
vector<cdb> si[maxn];
map<mp,cdb> ans;
void dfs1(int u,int fa,int rt)
{
	f[u]=0;fu[u]=u;bl[u]=rt;sz[rt]++;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa)
	{
		dfs1(v,u,rt);
		if (f[v]+1+f[u]>gd)
			gd=f[v]+1+f[u],gu=fu[u],gv=fu[v];
		if (f[v]+1>f[u])
			fu[u]=fu[v],f[u]=f[v]+1;
	}
}
void dfs2(int u,int fa,int dis)
{
	g[u]=max(g[u],dis);
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) dfs2(v,u,dis+1);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&q);
	for (int u,v,i=1;i<=m;i++)
		scanf("%d %d",&u,&v),add(u,v);
	for (int i=1;i<=n;i++)
	if (!bl[i]) {
		gu=gv=i;gd=0;dfs1(i,0,i);
		dfs2(gu,0,0);dfs2(gv,0,0);
		w[i]=gd;
		for (int j=0;j<=w[i];j++) s[i].pb(0),si[i].pb(0.0);
	}
	for (int i=1;i<=n;i++) s[bl[i]][g[i]]++,si[bl[i]][g[i]]+=g[i];
	for (int i=1;i<=n;i++)
	if (bl[i]==i) {
		for (int j=1;j<=w[i];j++)
			s[i][j]+=s[i][j-1],
			si[i][j]+=si[i][j-1];
	}
	for (int u,v,i=1;i<=q;i++)
	{
		scanf("%d %d",&u,&v);u=bl[u];v=bl[v];
		if (u==v) {puts("-1");continue;}
		int l=max(w[u],w[v]);
		if (ans.find(mp(u,v))!=ans.end())
			{printf("%.10lf\n",double(ans[mp(u,v)]));continue;}
		if (w[u]>w[v]) swap(u,v);
		double res=0.0,all=si[v][w[v]];
		for (int i=0;i<=w[u];i++)
		{
			int t=min(w[v],l-1-i),y=s[u][i]-(i?s[u][i-1]:0);
			if (t>=0)
				res+=(1.*s[v][t]*l+all-si[v][t]+1.*(sz[v]-s[v][t])*(i+1))*y;
			else
				res+=(all+1.*sz[v]*(i+1))*y;
		}
		res=res/sz[u]/sz[v];
		ans[mp(u,v)]=ans[mp(v,u)]=res;
		printf("%.10lf\n",double(res));
	}
	return 0;
}