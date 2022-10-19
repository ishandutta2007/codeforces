#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0,dfn_t=0;
LL ans=0;
int la[200002],deg[200002],dfn[200002],siz[200002];
char s[200002];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int l,r,o;
};
vector<bbb> vec[200002];
struct ccc
{
	int mn,cnt;
};
inline ccc merge(ccc a,ccc b)
{
	if(a.mn<b.mn)return a;
	if(a.mn>b.mn)return b;
	return (ccc){a.mn,a.cnt+b.cnt};
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
	int laz[800002];
	ccc a[800002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(a[k]=(ccc){0,1});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=merge(a[ls],a[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(a[k].mn+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])a[ls].mn+=laz[k],laz[ls]+=laz[k],a[rs].mn+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		a[k]=merge(a[ls],a[rs]);
	}
}S;
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
}
inline void dfs(int x)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),siz[x]+=siz[v];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s+(i-1)*m+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(i>2 && s[num(i-1,j)]=='D' && s[num(i-2,j)]=='U')add_edge(num(i,j),num(i-2,j));
			if(i+2<=n && s[num(i+1,j)]=='U' && s[num(i+2,j)]=='D')add_edge(num(i,j),num(i+2,j));
			if(j>2 && s[num(i,j-1)]=='R' && s[num(i,j-2)]=='L')add_edge(num(i,j),num(i,j-2));
			if(j+2<=m && s[num(i,j+1)]=='L' && s[num(i,j+2)]=='R')add_edge(num(i,j),num(i,j+2));
		}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(!deg[num(i,j)])dfs(num(i,j));
	for(int i=1;i<=n;++i)
		for(int j=1,x,y;j<=m;++j)
		{
			if(j<m && s[x=num(i,j)]=='L' && s[y=num(i,j+1)]=='R')
			{
				if((((x-1)%m+1)^((x-1)/m+1))&1)swap(x,y);
				vec[dfn[x]].push_back((bbb){dfn[y],dfn[y]+siz[y]-1,1}),vec[dfn[x]+siz[x]].push_back((bbb){dfn[y],dfn[y]+siz[y]-1,-1});
			}
			if(i<n && s[x=num(i,j)]=='U' && s[y=num(i+1,j)]=='D')
			{
				if((((x-1)%m+1)^((x-1)/m+1))&1)swap(x,y);
				vec[dfn[x]].push_back((bbb){dfn[y],dfn[y]+siz[y]-1,1}),vec[dfn[x]+siz[x]].push_back((bbb){dfn[y],dfn[y]+siz[y]-1,-1});
			}
		}
	S.build(1,1,dfn_t);
	for(int i=1;i<=dfn_t;++i)
	{
		for(int j=0;j<vec[i].size();++j)S.modify(1,1,dfn_t,vec[i][j].l,vec[i][j].r,vec[i][j].o);
		ans+=dfn_t-(S.a[1].mn? 0:S.a[1].cnt);
	}
	return 0&printf("%lld",ans);
}