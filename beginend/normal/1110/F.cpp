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
const LL inf=(LL)1e16;

int n,q,lef[N],rig[N],a[N][2];
LL ans[N],dep[N],mn[N*4],tag[N*4],val[N];
std::vector<int> vec1[N],vec2[N],vec[N];

void dfs1(int x)
{
	if (!vec1[x].size()) lef[x]=rig[x]=x;
	for (int i=0;i<vec1[x].size();i++)
	{
		int to=vec1[x][i],w=vec2[x][i];
		dep[to]=dep[x]+w;
		dfs1(to);
		if (!lef[x]) lef[x]=lef[to];
		rig[x]=rig[to];
	}
}

void push(int d)
{
	mn[ls]+=tag[d];mn[rs]+=tag[d];
	tag[ls]+=tag[d];tag[rs]+=tag[d];
	tag[d]=0;
}

void build(int d,int l,int r)
{
	if (l==r) {mn[d]=val[l];return;}
	int mid=(l+r)/2;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[d]=std::min(mn[ls],mn[rs]);
}

void ins(int d,int l,int r,int x,int y,LL w)
{
	if (x<=l&&r<=y) {tag[d]+=w;mn[d]+=w;return;}
	push(d);
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y,w);
	if (y>mid) ins(rs,mid+1,r,x,y,w);
	mn[d]=std::min(mn[ls],mn[rs]);
}

LL query(int d,int l,int r,int x,int y)
{
	if (l==x&&r==y) return mn[d];
	push(d);
	int mid=(l+r)/2;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return std::min(query(ls,l,mid,x,mid),query(rs,mid+1,r,mid+1,y));
}

void dfs2(int x)
{
	for (int i=0;i<vec[x].size();i++)
	{
		int id=vec[x][i];
		ans[id]=query(1,1,n,a[id][0],a[id][1])+dep[x];
	}
	for (int i=0;i<vec1[x].size();i++)
	{
		int to=vec1[x][i];
		ins(1,1,n,lef[to],rig[to],dep[x]*2-dep[to]*2);
		dfs2(to);
		ins(1,1,n,lef[to],rig[to],dep[to]*2-dep[x]*2);
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		vec1[x].pb(i);vec2[x].pb(y);
	}
	dfs1(1);
	for (int i=1;i<=n;i++)
		if (!vec1[i].size()) val[i]=dep[i]-dep[1]*2;
		else val[i]=inf;
	build(1,1,n);
	for (int i=1,x;i<=q;i++) scanf("%d%d%d",&x,&a[i][0],&a[i][1]),vec[x].pb(i);
	dfs2(1);
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}