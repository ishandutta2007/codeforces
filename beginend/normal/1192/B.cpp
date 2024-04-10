#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

typedef long long LL;

const int N=100005;

int n,q,cnt,last[N],a[N*2],tot,sta[N],end[N];
LL dis[N],m;
struct tree{LL tag,mn,mx1,mx2,mx3,mx4;}t[N*8];
struct edge{int to,next;LL w;}e[N*2];

void addedge(int u,int v,LL w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
	a[++tot]=x;sta[x]=tot;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dis[e[i].to]=dis[x]+e[i].w;
		dfs(e[i].to,x);
		a[++tot]=x;
	}
	end[x]=tot;
}

void updata(int d)
{
	t[d].mn=std::min(t[ls].mn,t[rs].mn);
	t[d].mx1=std::max(t[ls].mx1,t[rs].mx1);
	t[d].mx2=std::max(t[ls].mx1-t[rs].mn*2,std::max(t[ls].mx2,t[rs].mx2));
	t[d].mx3=std::max(t[rs].mx1-t[ls].mn*2,std::max(t[rs].mx3,t[ls].mx3));
	t[d].mx4=std::max(std::max(t[ls].mx2+t[rs].mx1,t[rs].mx3+t[ls].mx1),std::max(t[ls].mx4,t[rs].mx4));
}

void mark(int d,LL w)
{
	t[d].tag+=w;t[d].mx1+=w;t[d].mn+=w;
	t[d].mx2-=w;t[d].mx3-=w;
}

void pushdown(int d)
{
	LL w=t[d].tag;t[d].tag=0;
	mark(ls,w);mark(rs,w);
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].mn=t[d].mx1=dis[a[l]];t[d].mx2=t[d].mx3=-dis[a[l]];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	updata(d);
}

void ins(int d,int l,int r,int x,int y,LL z)
{
	if (x<=l&&r<=y) {mark(d,z);return;}
	pushdown(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,z);
	if (y>mid) ins(rs,mid+1,r,x,y,z);
	updata(d);
}

int main()
{
	scanf("%d%d%lld",&n,&q,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;LL w;scanf("%d%d%lld",&x,&y,&w);
		addedge(x,y,w);
	}
	dfs(1,0);
	build(1,1,tot);
	LL ans=0;
	while (q--)
	{
		int x;LL w;scanf("%d%lld",&x,&w);
		x=(x+ans)%(n-1)+1;w=(w+ans)%m;
		int p=e[x*2-1].to,q=e[x*2].to;LL del=w-e[x*2].w;
		e[x*2-1].w=e[x*2].w=w;
		if (sta[p]>sta[q]) ins(1,1,tot,sta[p],end[p],del);
		else ins(1,1,tot,sta[q],end[q],del);
		printf("%lld\n",ans=t[1].mx4);
	}
	return 0;
}