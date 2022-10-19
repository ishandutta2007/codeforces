#include<cstdio>
#define LL long long
int n,q,edge_t=0,N=0;
LL w,z,lastans=0;
int la[1000002]={},son[1000002],in[1000002],out[1000002];
LL a[2000002];
struct aaa
{
	int to,nx;
	LL val;
}edge[2000002];
inline LL min(LL x,LL y)
{
	return x<y? x:y;
}
inline LL max(LL x,LL y)
{
	return x>y? x:y;
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
	LL hmx[8000008],hmn[8000008],phmx_2mn[8000008],shmx_2mn[8000008],ans[8000008],laz[8000008];
	inline void pushup(int k,int ls,int rs)
	{
		hmx[k]=max(hmx[ls],hmx[rs]);
		hmn[k]=min(hmn[ls],hmn[rs]);
		phmx_2mn[k]=max(max(phmx_2mn[ls],phmx_2mn[rs]),hmx[rs]-2*hmn[ls]);
		shmx_2mn[k]=max(max(shmx_2mn[ls],shmx_2mn[rs]),hmx[ls]-2*hmn[rs]);
		ans[k]=max(max(ans[ls],ans[rs]),max(shmx_2mn[ls]+hmx[rs],hmx[ls]+phmx_2mn[rs]));
	}
	inline void pushdown(int k,int ls,int rs)
	{
		hmx[ls]+=laz[k],hmx[rs]+=laz[k];
		hmn[ls]+=laz[k],hmn[rs]+=laz[k];
		phmx_2mn[ls]-=laz[k],phmx_2mn[rs]-=laz[k];
		shmx_2mn[ls]-=laz[k],shmx_2mn[rs]-=laz[k];
		laz[ls]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)
		{
			hmx[k]=hmn[k]=a[l],phmx_2mn[k]=shmx_2mn[k]=-a[l],ans[k]=0;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,ls,rs);
	}
	inline void modify(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1)
		{
			hmx[k]+=d,hmn[k]+=d,phmx_2mn[k]-=d,shmx_2mn[k]-=d,laz[k]+=d;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);pushdown(k,ls,rs);
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		pushup(k,ls,rs);
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,LL z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,LL d)
{
	a[in[x]=(++N)]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(son[(i+1)/2]=v,x,d+edge[i].val),a[++N]=d;
	out[x]=N;
}
int main()
{
	read(n),read(q),read(w);
	for(int i=1,x,y;i<n;++i)read(x),read(y),read(z),add_edge(x,y,z);dfs(1,0,0),S.build(1,1,N);
	for(int s;q--;)read(s),read(z),s=(lastans+s)%(n-1)+1,z=(lastans+z)%w,S.modify(1,1,N,in[son[s]],out[son[s]],z-edge[2*s].val),edge[2*s-1].val=edge[2*s].val=z,printf("%lld\n",lastans=S.ans[1]);
	return 0;
}