#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=500005;

int n,g[N*2],tot,pos;
LL mx;
struct tree{LL mx,tag;int pos;}t[N*8];
struct data{int x,y,w;}a[N];
std::vector<int> vec[N*2];

void pushdown(int d)
{
	LL w=t[d].tag;t[d].tag=0;
	t[ls].mx+=w;t[ls].tag+=w;
	t[rs].mx+=w;t[rs].tag+=w;
}

void updata(int d)
{
	if (t[ls].mx>t[rs].mx) t[d].mx=t[ls].mx,t[d].pos=t[ls].pos;
	else t[d].mx=t[rs].mx,t[d].pos=t[rs].pos;
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].mx=g[l];t[d].pos=l;return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) {t[d].mx+=w;t[d].tag+=w;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,w);
	if (y>mid) ins(rs,mid+1,r,x,y,w);
	updata(d);
}

void query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) {if (t[d].mx>mx) mx=t[d].mx,pos=t[d].pos;return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) query(ls,l,mid,x,y);
	if (y>mid) query(rs,mid+1,r,x,y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		if (a[i].x>a[i].y) std::swap(a[i].x,a[i].y);
		g[++tot]=a[i].x;g[++tot]=a[i].y;
	}
	std::sort(g+1,g+tot+1);
	tot=std::unique(g+1,g+tot+1)-g-1;
	for (int i=1;i<=n;i++)
	{
		a[i].x=std::lower_bound(g+1,g+tot+1,a[i].x)-g;a[i].y=std::lower_bound(g+1,g+tot+1,a[i].y)-g;
		vec[a[i].y].pb(i);
	}
	build(1,1,tot);
	LL ans=0;
	int lef=2e9,rig=2e9;
	for (int i=1;i<=tot;i++)
	{
		for (int j=0;j<vec[i].size();j++)
			ins(1,1,tot,1,a[vec[i][j]].x,a[vec[i][j]].w);
		mx=pos=0;
		query(1,1,tot,1,i);
		if (mx-g[i]>ans) ans=mx-g[i],lef=g[pos],rig=g[i];
	}
	printf("%lld\n%d %d %d %d\n",ans,lef,lef,rig,rig);
	return 0;
}