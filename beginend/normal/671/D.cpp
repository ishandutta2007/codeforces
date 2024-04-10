#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;

const int N=300005;
const LL inf=(LL)1e15;

int n,m,tim,dfn[N],mx[N],mn[N],last[N],cnt,c[N];
LL f[N];
vector<int> w[N],d[N];
struct edge{int to,next;}e[N*2];
struct tree{LL tag,mn;}t[N*5];

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

void inc(LL &x,LL y)
{
	if (x+y>inf) x=inf;
	else x+=y;
}

void pushdown(int d,int l,int r)
{
	if (!t[d].tag||l==r) return;
	LL w=t[d].tag;t[d].tag=0;
	inc(t[d*2].mn,w);inc(t[d*2+1].mn,w);
	inc(t[d*2].tag,w);inc(t[d*2+1].tag,w);
}

void ins(int d,int l,int r,int x,LL y)
{
	pushdown(d,l,r);
	if (l==r)
	{
		t[d].mn=y;return;
	}
	int mid=(l+r)/2;
	if (x<=mid) ins(d*2,l,mid,x,y);
	else ins(d*2+1,mid+1,r,x,y);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

void modify(int d,int l,int r,int x,int y,LL z)
{
	if (x>y) return;
	pushdown(d,l,r);
	if (l==x&&r==y)
	{
		inc(t[d].mn,z);
		inc(t[d].tag,z);
		return;
	}
	int mid=(l+r)/2;
	modify(d*2,l,mid,x,min(y,mid),z);
	modify(d*2+1,mid+1,r,max(x,mid+1),y,z);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

LL query(int d,int l,int r,int x,int y)
{
	if (x>y) return inf;
	pushdown(d,l,r);
	if (l==x&&r==y) return t[d].mn;
	int mid=(l+r)/2;
	return min(query(d*2,l,mid,x,min(y,mid)),query(d*2+1,mid+1,r,max(x,mid+1),y));
}

void dfs(int x,int fa)
{
	mn[x]=tim+1;
	for (int i=0;i<w[x].size();i++) dfn[w[x][i]]=++tim;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	mx[x]=tim;
}

void solve(int x,int fa)
{
	LL s=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		solve(e[i].to,x);
		inc(s,f[e[i].to]);
	}
	if (x==1)
	{
		f[x]=s;
		return;
	}
	for (int i=0;i<w[x].size();i++) ins(1,1,m,dfn[w[x][i]],s+c[w[x][i]]);
	for (int i=0;i<d[x].size();i++) ins(1,1,m,dfn[d[x][i]],inf);
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		modify(1,1,m,mn[e[i].to],mx[e[i].to],s-f[e[i].to]);
	}
	f[x]=query(1,1,m,mn[x],mx[x]);
}

int main()
{
	n=read();m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<=m*4;i++) t[i].mn=inf;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();c[i]=read();
		w[x].push_back(i);d[y].push_back(i);
	}
	dfs(1,0);
	solve(1,0);
	if (f[1]>=inf) puts("-1");
	else printf("%I64d",f[1]);
	return 0;
}