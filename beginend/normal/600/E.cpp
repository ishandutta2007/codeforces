#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,mx[N],mn[N],sz,dfn[N],tot[N],col[N],last[N],size[N],Mx,cnt;
struct edge{int to,next;}e[N*2];
LL sum[N],ans[N];

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

void dfs(int x,int fa)
{
	mn[x]=++sz;dfn[sz]=x;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
	mx[x]=sz;
}

void add(int x)
{
	for (int i=mn[x];i<=mx[x];i++)
	{
		int y=col[dfn[i]];
		sum[tot[y]]-=y;
		sum[++tot[y]]+=y;
		Mx=max(Mx,tot[y]);
	}
}

void del(int x)
{
	for (int i=mn[x];i<=mx[x];i++)
	{
		int y=col[dfn[i]];
		sum[tot[y]]-=y;
		sum[--tot[y]]+=y;
		if (!sum[Mx]) Mx--;
	}
}

void solve(int x,int fa)
{
	int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa&&size[e[i].to]>size[k]) k=e[i].to;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa&&e[i].to!=k) solve(e[i].to,x),del(e[i].to);
	if (k) solve(k,x);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa&&e[i].to!=k) add(e[i].to);
	sum[tot[col[x]]]-=col[x];
	sum[++tot[col[x]]]+=col[x];
	Mx=max(Mx,tot[col[x]]);
	ans[x]=sum[Mx];
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) col[i]=read(),sum[0]+=i;
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	dfs(1,0);
	solve(1,0);
	for (int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}