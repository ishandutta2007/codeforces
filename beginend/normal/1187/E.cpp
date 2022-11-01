#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,cnt,last[N],size[N];
struct edge{int to,next;}e[N*2];
LL f[N],ans;

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs1(int x,int fa)
{
	size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		f[x]+=f[e[i].to];
	}
	f[x]+=size[x];
}

void dfs2(int x,int fa)
{
	f[x]+=f[fa]-size[x];
	ans=std::max(ans,f[x]);
	f[x]+=n-size[x];
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		f[x]+=size[x]-size[e[i].to]-f[e[i].to];
		dfs2(e[i].to,x);
		f[x]-=size[x]-size[e[i].to]-f[e[i].to];
	}
	f[x]-=n-size[x];
	f[x]-=f[fa]-size[x];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",ans+n);
	return 0;
}