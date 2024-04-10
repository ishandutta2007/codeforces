#include<bits/stdc++.h>
#define Mx 17
#define eps 1e-9
using namespace std;
int n,q,edge_t=0,dfn_t=0;
int a[200002],fa[200002],la[200002],dfn[200002],dep[200002],to[200002];
int mn[200002][18];
struct aaa
{
	int to,nx;
}edge[400002];
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline int merge(int x,int y)
{
	return dep[x]<dep[y]? x:y;
}
inline int LCA(int x,int y)
{
	if(x==y)return x;
	if(dfn[x]>dfn[y])swap(x,y);
	int len=log2(dfn[y]-dfn[x])+eps;
	return fa[merge(mn[dfn[x]+1][len],mn[dfn[y]-(1<<len)+1][len])];
}
inline int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
struct bbb
{
	bool ok;
	int p[2];
};
inline bool check(bbb &k,int a,int b,int c,int d)
{
	int t=dis(a,b);
	if(dis(a,c)+dis(b,c)!=t || dis(a,d)+dis(b,d)!=t)return 0;
	return k=(bbb){1,a,b},1;
}
inline bbb merge(bbb a,bbb b)
{
	bbb k={0,{0,0}};
	if(!a.ok || !b.ok)return k;
	if(check(k,a.p[0],a.p[1],b.p[0],b.p[1]))return k;
	if(check(k,a.p[0],b.p[0],a.p[1],b.p[1]))return k;
	if(check(k,a.p[0],b.p[1],a.p[1],b.p[0]))return k;
	if(check(k,a.p[1],b.p[0],a.p[0],b.p[1]))return k;
	if(check(k,a.p[1],b.p[1],a.p[0],b.p[0]))return k;
	if(check(k,b.p[0],b.p[1],a.p[0],a.p[1]))return k;
	return k;
}
struct SegTree
{
	bbb t[800002];
	inline void maintain(int k,int x)
	{
		t[k]=(bbb){1,{to[x],to[x]}};
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)return maintain(k,l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),t[k]=merge(t[ls],t[rs]);
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return maintain(k,x);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		t[k]=merge(t[ls],t[rs]);
	}
	inline int query(int k,int l,int r,bbb x)
	{
		if(l==r)return l-1;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		bbb tmp=merge(x,t[ls]);
		if(tmp.ok)return query(rs,mid+1,r,tmp);
		return query(ls,l,mid,x);
	}
}S;
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	mn[dfn[x]=(++dfn_t)][0]=x;
	for(int i=la[x],v;i;i=edge[i].nx)dep[v=edge[i].to]=dep[x]+1,dfs(v);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)mn[j][i]=merge(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[++a[i]]=i;
	for(int i=2;i<=n;++i)scanf("%d",&fa[i]),add_edge(fa[i],i);
	dfs(dep[1]=1),get_LCA(),S.build(1,1,n),scanf("%d",&q);
	for(int o,x,y;q--;)
	{
		scanf("%d",&o);
		if(o==1)scanf("%d%d",&x,&y),swap(a[x],a[y]),swap(to[a[x]],to[a[y]]),S.modify(1,1,n,a[x]),S.modify(1,1,n,a[y]);
		else printf("%d\n",S.t[1].ok? n:S.query(1,1,n,(bbb){1,{to[1],to[1]}}));
	}
	return 0;
}