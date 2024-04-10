#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=1000005;

int n,k,a[N],stack[N],cnt,last[N],dfn[N],tim,mx[N];
bool vis[N];
struct tree{int mx,tag;}t[N*4];
struct edge{int to,next;}e[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
	vis[x]=1;dfn[x]=++tim;
	for (int i=last[x];i;i=e[i].next) dfs(e[i].to);
	mx[x]=tim;
}

void pushdown(int d)
{
	int w=t[d].tag;t[d].tag=0;
	t[ls].tag+=w;t[ls].mx+=w;
	t[rs].tag+=w;t[rs].mx+=w;
}

void ins(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) {t[d].tag++;t[d].mx++;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y);
	if (y>mid) ins(rs,mid+1,r,x,y);
	t[d].mx=std::max(t[ls].mx,t[rs].mx);
}

void cov(int d,int l,int r,int x,int y)
{
	if (l==r) {t[d].mx=y;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) cov(ls,l,mid,x,y);
	else cov(rs,mid+1,r,x,y);
	t[d].mx=std::max(t[ls].mx,t[rs].mx);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int top=0;
	for (int i=n;i>=1;i--)
	{
		while (top&&a[stack[top]]<=a[i]) top--;
		if (top) addedge(stack[top],i);
		stack[++top]=i;
	}
	for (int i=n;i>=1;i--) if (!vis[i]) dfs(i);
	for (int i=1;i<=k;i++) ins(1,1,n,dfn[i],mx[i]);
	printf("%d ",t[1].mx);
	for (int i=k+1;i<=n;i++)
	{
		ins(1,1,n,dfn[i],mx[i]);
		cov(1,1,n,dfn[i-k],-n);
		printf("%d ",t[1].mx);
	}
	return 0;
}