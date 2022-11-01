#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,k,cnt,last[N],fa[N][20],dep[N],dx,dy,dl,col[N];
bool vis[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs1(int x)
{
	dep[x]=dep[fa[x][0]]+1;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x][0]) continue;
		fa[e[i].to][0]=x;
		dfs1(e[i].to);
	}
}

int get_dis(int x,int y)
{
	int p=x,q=y;
	if (dep[x]<dep[y]) std::swap(x,y);
	for (int i=18;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return dep[p]+dep[q]-dep[x]*2;
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return dep[p]+dep[q]-dep[fa[x][0]]*2;
}

void dfs2(int x,int d,int fa)
{
	if (d>dl) dl=d,dx=x;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs2(e[i].to,d+1,x);
}

int main()
{
	scanf("%d%d",&n,&k);
	k--;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs1(1);
	if (k==1)
	{
		puts("Yes");
		for (int i=1;i<=n;i++) printf("%d ",dep[i]%2+1);
		return 0;
	}
	dfs2(1,0,0);
	dy=dx;dl=dx=0;
	dfs2(dy,0,0);
	for (int i=1;i<=n;i++)
	{
		int d1=get_dis(i,dx),d2=get_dis(i,dy);
		if (d1+d2==dl) vis[i]=1,col[i]=d1%(k+1);
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		int d1=get_dis(i,dx),d2=get_dis(i,dy);
		if (d1>=k&&d2>=k) {puts("No");return 0;}
		else if (d1>=k) col[i]=d1%(k+1);
		else if (d2>=k) col[i]=(dl-d2)%(k+1);
		else if (d1>d2) col[i]=d1%(k+1);
		else if (d1<d2) col[i]=(dl-d2)%(k+1);
		else col[i]=0;
	}
	puts("Yes");
	for (int i=1;i<=n;i++) printf("%d ",col[i]+1);
	return 0;
}