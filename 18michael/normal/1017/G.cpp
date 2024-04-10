#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q,edge_t=0,dfn_t=0;
int la[100002],siz[100002],son[100002],fa[100002],dfn[100002],top[100002];
struct aaa
{
	int to,nx;
}edge[100002];
struct bbb
{
	LL sum,mx;
};
inline bbb merge(bbb a,bbb b)
{
	return (bbb){a.sum+b.sum,max(b.mx,a.mx+b.sum)};
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	bbb a[400002];
	int len[400002];
	LL laz[400002];
	inline void pushdown(int k,int ls,int rs)
	{
		if(laz[k]<1)a[ls].sum=len[ls]*laz[k],a[rs].sum=len[rs]*laz[k],laz[ls]=a[ls].mx=laz[rs]=a[rs].mx=laz[k],laz[k]=1;
	}
	inline void build(int k,int l,int r)
	{
		a[k]=(bbb){-(len[k]=r-l+1),-1},laz[k]=1;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=merge(a[ls],a[rs]);
	}
	inline void add(int k,int l,int r,int x,LL d)
	{
		if(l==r)return (void)(a[k].sum+=d,a[k].mx+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(x<=mid)add(ls,l,mid,x,d);
		else add(rs,mid+1,r,x,d);
		a[k]=merge(a[ls],a[rs]);
	}
	inline void cover(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(a[k].sum=len[k]*d,laz[k]=a[k].mx=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)cover(ls,l,mid,l1,r1,d);
		else if(l1>mid)cover(rs,mid+1,r,l1,r1,d);
		else cover(ls,l,mid,l1,r1,d),cover(rs,mid+1,r,l1,r1,d);
		a[k]=merge(a[ls],a[rs]);
	}
	inline bbb query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return a[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,r1),query(rs,mid+1,r,l1,r1));
	}
}S;
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		dfs(v=edge[i].to),fa[v]=x,siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
inline void dfs1(int x,int t)
{
	dfn[x]=(++dfn_t),top[x]=t;
	if(son[x])dfs1(son[x],t);
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=son[x])dfs1(v,v);
}
inline int Query(int x)
{
	bbb tmp=(bbb){0,-1};
	for(;x;x=fa[top[x]])tmp=merge(S.query(1,1,n,dfn[top[x]],dfn[x]),tmp);
	return tmp.mx;
}
int main()
{
	scanf("%d%d",&n,&q),S.build(1,1,n);
	for(int i=2,x;i<=n;++i)scanf("%d",&x),add_edge(x,i);
	dfs(1),dfs1(1,1);
	for(int o,x;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)S.add(1,1,n,dfn[x],1);
		else if(o==2)S.cover(1,1,n,dfn[x],dfn[x]+siz[x]-1,-1),S.add(1,1,n,dfn[x],-Query(x)-1);
		else puts(Query(x)>=0? "black":"white");
	}
	return 0;
}