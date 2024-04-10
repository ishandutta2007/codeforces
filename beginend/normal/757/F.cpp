#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define pb(x) push_back(x)
using namespace std;

typedef long long LL;

const int N=200005;
const LL inf=(LL)1e15;

int n,m,s,cnt,last[N],tot,a[N],fa[N][20],dep[N],deg[N],size[N];
bool vis[N];
queue<int> que;
vector<int> vec[N];
LL dis[N];
struct edge{int to,next,w,op;}e[N*3];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void spfa()
{
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[s]=0;que.push(s);vis[s]=1;
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (dis[x]+e[i].w<dis[e[i].to])
			{
				dis[e[i].to]=dis[x]+e[i].w;
				if (!vis[e[i].to]) que.push(e[i].to),vis[e[i].to]=1;
			}
		vis[x]=0;
	}
}

void build()
{
	que.push(s);
	memset(vis,0,sizeof(vis));
	while (!que.empty())
	{
		int u=que.front();que.pop();
		for (int i=last[u];i;i=e[i].next)
			if (dis[u]+e[i].w==dis[e[i].to])
			{
				if (!vis[e[i].to]) que.push(e[i].to),vis[e[i].to]=1;
				e[i].op=1;vec[e[i].to].pb(u);deg[e[i].to]++;
			}
	}
	a[++tot]=s;
	for (int i=1;i<=tot;i++)
	{
		int x=a[i];
		for (int j=last[x];j;j=e[j].next)
			if (e[j].op==1)
			{
				deg[e[j].to]--;
				if (!deg[e[j].to]) a[++tot]=e[j].to;
			}
	}
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

void solve()
{
	for (int i=1;i<=tot;i++)
	{
		int x=a[i];
		for (int j=0;j<vec[x].size();j++)
			if (!fa[x][0]) fa[x][0]=vec[x][j];
			else fa[x][0]=get_lca(fa[x][0],vec[x][j]);
		dep[x]=dep[fa[x][0]]+1;
		for (int j=1;j<=18;j++) fa[x][j]=fa[fa[x][j-1]][j-1];
	}
	for (int i=tot;i>=1;i--) size[a[i]]++,size[fa[a[i]][0]]+=size[a[i]];
	int ans=0;
	for (int i=2;i<=tot;i++) ans=max(ans,size[a[i]]);
	printf("%d",ans);
}

int main()
{
	n=read();m=read();s=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		addedge(x,y,z);
	}
	spfa();
	build();
	solve();
	return 0;
}