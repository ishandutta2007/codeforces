#include<bits/stdc++.h>
#define Mx 16
#define LL long long
using namespace std;
int n,q,edge_t=0,dfn_t=0,rt=1;
int a[100002],la[100002],dfn[100002],siz[100002],dep[100002],to[100002];
int fa[100002][18];
struct aaa
{
	int to,nx;
}edge[200002];
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
	LL sum[400002],laz[400002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(sum[k]=a[to[l]]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),sum[k]=sum[ls]+sum[rs];
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(sum[k]+=1LL*d*(r-l+1),laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		sum[ls]+=laz[k]*(mid-l+1),laz[ls]+=laz[k],sum[rs]+=laz[k]*(r-mid),laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		sum[k]=sum[ls]+sum[rs];
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		sum[ls]+=laz[k]*(mid-l+1),laz[ls]+=laz[k],sum[rs]+=laz[k]*(r-mid),laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S;
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	siz[to[dfn[x]=(++dfn_t)]=x]=1,fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1),siz[x]+=siz[v];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline bool in(int x,int y)
{
	return dfn[x]>=dfn[y] && dfn[x]<dfn[y]+siz[y];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1),S.build(1,1,n);
	for(int o,x,y,z,w,a,b;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)rt=x;
		else if(o==2)
		{
			scanf("%d%d",&y,&z),w=LCA(x,y),a=LCA(x,rt),b=LCA(y,rt);
			if((a==rt && b==w) || (b==rt && a==w))S.modify(1,1,n,1,n,z);
			else if(LCA(w,rt)!=w)S.modify(1,1,n,dfn[w],dfn[w]+siz[w]-1,z);
			else
			{
				if(b==w)swap(a,b),swap(x,y);
				a=rt;
				for(int i=Mx;~i;--i)if(dep[fa[a][i]]>dep[b])a=fa[a][i];
				S.modify(1,1,n,1,n,z),S.modify(1,1,n,dfn[a],dfn[a]+siz[a]-1,-z);
			}
		}
		else if(rt==x)printf("%lld\n",S.query(1,1,n,1,n));
		else if(in(rt,x))
		{
			a=rt;
			for(int i=Mx;~i;--i)if(dep[fa[a][i]]>dep[x])a=fa[a][i];
			printf("%lld\n",S.query(1,1,n,1,n)-S.query(1,1,n,dfn[a],dfn[a]+siz[a]-1));
		}
		else printf("%lld\n",S.query(1,1,n,dfn[x],dfn[x]+siz[x]-1));
	}
	return 0;
}