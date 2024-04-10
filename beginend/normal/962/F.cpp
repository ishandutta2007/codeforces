#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,m,cnt,last[N],num[N],dep[N],s[N],f[N],g[N],fa[N];
bool vis[N];
struct edge{int to,next;bool tag;}e[N*2];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs1(int x)
{
	vis[x]=1;dep[x]=dep[fa[x]]+1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		if (!vis[e[i].to]) fa[e[i].to]=x,num[e[i].to]=i,dfs1(e[i].to);
		else if (dep[e[i].to]<dep[x]) s[x]++,s[e[i].to]--;
	}
}

void dfs2(int x)
{
	vis[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		if (!vis[e[i].to]) dfs2(e[i].to),s[x]+=s[e[i].to];
	}
}

void dfs3(int x)
{
	vis[x]=1;g[x]=(s[x]>1)+g[fa[x]];
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		if (!vis[e[i].to]) dfs3(e[i].to);
		else if (dep[e[i].to]<dep[x]&&g[x]-g[e[i].to]==0)
		{
			int y=find(x);e[i].tag=e[i^1].tag=1;
			while (dep[y]>dep[e[i].to])
			{
				e[num[y]].tag=e[num[y]^1].tag=1;
				f[y]=find(fa[y]);y=find(y);
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);cnt=1;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs1(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) if (!vis[i]) dfs2(i);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++) if (!vis[i]) dfs3(i);
	int ans=0;
	for (int i=2;i<=cnt;i+=2) ans+=e[i].tag;
	printf("%d\n",ans);
	for (int i=2;i<=cnt;i+=2)
		if (e[i].tag) printf("%d ",i/2);
	return 0;
}