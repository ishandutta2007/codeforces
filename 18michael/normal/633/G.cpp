#include<cstdio>
#include<bitset>
#define Mx 999
using namespace std;
int n,m,q,edge_t=0,dfn_t=0,p_t=0;
int a[100002],la[100002]={},dfn[100002],siz[100002],p[1002],to[100002];
bitset<1000> P,M;bool u[1002]={};
struct aaa
{
	int to,nx;
}edge[200002];
inline void add(int &x,int y)
{
	if((x+=y)>=m)x-=m;
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
	bitset<1000> bs[400002];
	int laz[400002];
	inline void upd(int k,int x)
	{
		add(laz[k],x),bs[k]=(((bs[k]<<x)|(bs[k]>>(m-x)))&M);
	}
	inline void build(int k,int l,int r)
	{
		if(l==r){bs[k][a[to[l]]]=1;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),bs[k]=(bs[ls]|bs[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1){upd(k,d);return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])upd(ls,laz[k]),upd(rs,laz[k]),laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		bs[k]=(bs[ls]|bs[rs]);
	}
	inline bitset<1000> query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return bs[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])upd(ls,laz[k]),upd(rs,laz[k]),laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return (query(ls,l,mid,l1,mid)|query(rs,mid+1,r,mid+1,r1));
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	to[dfn[x]=(++dfn_t)]=x,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),siz[x]+=siz[v];
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i,P[i]=1;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	init(),read(n),read(m);
	for(int i=0;i<m;i++)M[i]=1;
	for(int i=1;i<=n;i++)read(a[i]),a[i]%=m;
	for(int i=1,x,y;i<n;i++)read(x),read(y),add_edge(x,y);
	dfs(1,0),S.build(1,1,n),read(q);
	for(int opt,x,y;q--;)
	{
		read(opt),read(x);
		if(opt==1)
		{
			read(y);
			if(y%=m)S.modify(1,1,n,dfn[x],dfn[x]+siz[x]-1,y);
		}
		else printf("%d\n",(S.query(1,1,n,dfn[x],dfn[x]+siz[x]-1)&P).count());
	}
	return 0;
}