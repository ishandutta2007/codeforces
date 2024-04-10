#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,m,q,cnt,last[N],dfn[N],low[N],top,stack[N],tim,now,bel[N],c[N],tot,dep[N],fa[N][20],f[N],g[N];
bool vis[N],ins[N];
struct edge{int to,next;}e[N*4];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void tarjan(int x,int from)
{
	bel[x]=now;dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (i==(from^1)) continue;
		if (!dfn[e[i].to])
		{
			tarjan(e[i].to,i);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (ins[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	}
	if (dfn[x]==low[x])
	{
		int y=0;tot++;
		while (y!=x)
		{
			y=stack[top];top--;
			c[y]=tot;ins[y]=0;
		}
	}
}

void dfs(int x)
{
	dep[x]=dep[fa[x][0]]+1;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]) fa[e[i].to][0]=x,dfs(e[i].to);
}

int get_lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=18;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

void get(int x)
{
	vis[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		get(e[i].to);
		f[x]+=f[e[i].to];
		g[x]+=g[e[i].to];
	}
}

int main()
{
	n=read();m=read();q=read();cnt=1;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) now++,tarjan(i,0);
	memset(last,0,sizeof(last));
	int tmp=cnt;
	for (int i=2;i<=tmp;i+=2)
	{
		int x=e[i].to,y=e[i^1].to;
		if (c[x]!=c[y]) addedge(c[x],c[y]);
	}
	for (int i=1;i<=tot;i++) if (!dep[i]) dfs(i);
	while (q--)
	{
		int x=read(),y=read();
		if (bel[x]!=bel[y]) {puts("No");return 0;}
		x=c[x];y=c[y];int w=get_lca(x,y);
		f[x]++;f[w]--;g[y]++;g[w]--;
	}
	for (int i=1;i<=tot;i++) if (!vis[i]) get(i);
	for (int i=1;i<=tot;i++) if (f[i]&&g[i]) {puts("No");return 0;}
	puts("Yes");
	return 0;
}