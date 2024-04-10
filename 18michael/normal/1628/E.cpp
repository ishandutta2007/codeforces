#include<cstdio>
#include<algorithm>
#define Mx 19
using namespace std;
int n,q,tot,edge_t=0,dfn_t=0;
int X[300002],Y[300002],Z[300002],id[300002],rt[600002],la[600002]={},val[600002],dfn[600002],dep[600002],to[600002];
int fa[600002][22];
struct aaa
{
	int to,nx;
}edge[600002];
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
	int laz[2400002],mn[2400002],mx[2400002],mn1[2400002],mx1[2400002];
	inline void build(int k,int l,int r)
	{
		laz[k]=-1,mn[k]=tot+1,mx[k]=0;
		if(l==r){mn1[k]=mx1[k]=dfn[l];return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),mn1[k]=min(mn1[ls],mn1[rs]),mx1[k]=max(mx1[ls],mx1[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)
		{
			if(d)mn[k]=mn1[k],mx[k]=mx1[k];else mn[k]=tot+1,mx[k]=0;
			laz[k]=d;return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(~laz[k])
		{
			if(laz[k])mn[ls]=mn1[ls],mx[ls]=mx1[ls],mn[rs]=mn1[rs],mx[rs]=mx1[rs];else mn[ls]=mn[rs]=tot+1,mx[ls]=mx[rs]=0;
			laz[ls]=laz[rs]=laz[k],laz[k]=-1;
		}
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mn[k]=min(mn[ls],mn[rs]),mx[k]=max(mx[ls],mx[rs]);
	}
}S;
inline bool cmp(int x,int y)
{
	return Z[x]<Z[y]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int d)
{
	dep[to[dfn[x]=(++dfn_t)]=x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to,d+1);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)for(int j=1;j<=tot;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
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
int main()
{
	scanf("%d%d",&n,&q),tot=n;
	for(int i=1;i<=n;++i)val[rt[i]=i]=-1;
	for(int i=1;i<n;++i)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),id[i]=i;
	sort(id+1,id+n,cmp);
	for(int i=1;i<n;++i)getroot(X[id[i]]),getroot(Y[id[i]]),add_edge((++tot),rt[X[id[i]]]),add_edge(tot,rt[Y[id[i]]]),val[rt[rt[X[id[i]]]]=rt[rt[Y[id[i]]]]=rt[tot]=fa[rt[X[id[i]]]][0]=fa[rt[Y[id[i]]]][0]=tot]=Z[id[i]];
	dfs(tot,1),get_LCA(),S.build(1,1,n);
	for(int o,x,y;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==3)printf("%d\n",S.mx[1]? val[LCA(LCA(to[S.mn[1]],to[S.mx[1]]),x)]:-1);
		else scanf("%d",&y),S.modify(1,1,n,x,y,(o==1));
	}
	return 0;
}