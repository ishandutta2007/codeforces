#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,q,edge_t=0,dfn_t=0,inv;LL ans;
int la[150002],siz[150002],son[150002],fa[150002],dfn[150002],top[150002],bot[150002],sum[150002];
struct aaa
{
	int to,nx;
}edge[300002];
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
	LL sum[600002],laz[600002];
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)return (void)(sum[k]=(sum[k]+(LL)d*(r-l+1))%mod,laz[k]=(laz[k]+d)%mod);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])sum[ls]=(sum[ls]+laz[k]*(mid-l+1))%mod,laz[ls]=(laz[ls]+laz[k])%mod,sum[rs]=(sum[rs]+laz[k]*(r-mid))%mod,laz[rs]=(laz[rs]+laz[k])%mod,laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		sum[k]=(sum[ls]+sum[rs])%mod;
	}
	inline LL query(int k,int l,int r,int x)
	{
		if(l==r)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])sum[ls]=(sum[ls]+laz[k]*(mid-l+1))%mod,laz[ls]=(laz[ls]+laz[k])%mod,sum[rs]=(sum[rs]+laz[k]*(r-mid))%mod,laz[rs]=(laz[rs]+laz[k])%mod,laz[k]=0;
		if(x<=mid)return query(ls,l,mid,x);
		return query(rs,mid+1,r,x);
	}
}S,S1;
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1,fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	dfn[x]=(++dfn_t),top[x]=t;
	if(son[x])dfs1(son[x],x,t);
	else bot[t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
int main()
{
	scanf("%d%d",&n,&q),inv=Pow(n,mod-2);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0),dfs1(1,0,1);
	for(int o,x,y;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)scanf("%d",&y),sum[x]=(sum[x]+y)%mod,S.modify(1,1,n,1,dfn[x]-1,((LL)y*siz[x])%mod),S.modify(1,1,n,dfn[x]+siz[x],n,((LL)y*siz[x])%mod),S.modify(1,1,n,dfn[x],dfn[x],((LL)y*n)%mod),S1.modify(1,1,n,dfn[x]+1,dfn[bot[top[x]]],((LL)y*(n-siz[son[x]]))%mod);
		else
		{
			for(ans=S.query(1,1,n,dfn[x]);x;x=fa[top[x]])ans=(ans+S1.query(1,1,n,dfn[x])+(LL)sum[fa[top[x]]]*(n-siz[top[x]]))%mod;
			printf("%lld\n",(ans*inv)%mod);
		}
	}
	return 0;
}