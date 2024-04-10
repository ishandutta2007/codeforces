#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=1000005;

int n,q,tim,dfn[N],bel[N],last[N],mx[N],a[N*2][3],val[N],cnt;
LL dep[N],mn[N*4],tag[N*4];
struct edge{int to,next,w;}e[N];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
	dfn[x]=++tim;bel[tim]=x;
	for (int i=last[x];i;i=e[i].next)
		dep[e[i].to]=dep[x]+e[i].w,dfs(e[i].to);
	mx[x]=tim;
}

void pushdown(int d)
{
	LL w=tag[d];tag[d]=0;
	mn[ls]+=w;tag[ls]+=w;
	mn[rs]+=w;tag[rs]+=w;
}

void build(int d,int l,int r)
{
	if (l==r) {mn[d]=(LL)val[bel[l]]+dep[bel[l]];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[d]=std::min(mn[ls],mn[rs]);
}

void ins(int d,int l,int r,int x,int y,int z)
{
	if (x<=l&&r<=y) {mn[d]+=z;tag[d]+=z;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	mn[d]=std::min(mn[ls],mn[rs]);
}

LL get_mn(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return mn[d];
	pushdown(d);
	int mid=(l+r)/2;
	if (y<=mid) return get_mn(ls,l,mid,x,y);
	else if (x>mid) return get_mn(rs,mid+1,r,x,y);
	else return std::min(get_mn(ls,l,mid,x,y),get_mn(rs,mid+1,r,x,y));
}

LL get_dep(int x)
{
	return get_mn(1,1,n,dfn[x],dfn[x])-val[x];
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n*2-2;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	for (int i=1;i<n;i++) addedge(a[i][0],a[i][1],a[i][2]);
	for (int i=1;i<n;i++) val[a[i+n-1][0]]=a[i+n-1][2];
	dfs(1);
	build(1,1,n);
	while (q--)
	{
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			if (x<n) ins(1,1,n,dfn[a[x][1]],mx[a[x][1]],y-a[x][2]);
			else ins(1,1,n,dfn[a[x][0]],dfn[a[x][0]],y-a[x][2]);
			a[x][2]=y;
			if (x>=n) val[a[x][0]]=y;
		}
		else
		{
			if (dfn[y]>=dfn[x]&&dfn[y]<=mx[x]) printf("%lld\n",get_dep(y)-get_dep(x));
			else printf("%lld\n",get_dep(y)+get_mn(1,1,n,dfn[x],mx[x])-get_dep(x));
		}
	}
	return 0;
}