#include<bits/stdc++.h>
using namespace std;
int n,k,d,t,las=1,stmn_t,stmx_t;
int a[200002],stmn[200002],stmx[200002];
map<int,int> mp;
struct aaa
{
	int l,r;
}ans={0,-1};
inline void upd(aaa &x,aaa y)
{
	if(y.r-y.l>x.r-x.l || (y.r-y.l==x.r-x.l && y.l<x.l))x=y;
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
	int mn[800002],laz[800002];
	inline void build(int k,int l,int r)
	{
		laz[k]=0;
		if(l==r)return (void)(mn[k]=l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),mn[k]=min(mn[ls],mn[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(mn[k]+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])mn[ls]+=laz[k],laz[ls]+=laz[k],mn[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mn[k]=min(mn[ls],mn[rs]);
	}
	inline int find(int k,int l,int r,int x,int d)
	{
		if(l==r)return mn[k]<=d? l:0;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k),res=0;
		if(laz[k])mn[ls]+=laz[k],laz[ls]+=laz[k],mn[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(x<=mid && mn[ls]<=d)res=find(ls,l,mid,x,d);
		if(!res)res=find(rs,mid+1,r,x,d);
		return res;
	}
}S;
inline void solve(int l,int r)
{
	S.build(1,1,t=r-l+1),stmn_t=stmx_t=0,las=1,mp.clear();
	for(int i=1;i<=t;++i)
	{
		a[i+l-1]=floor(1.0*a[i+l-1]/d);
		while(stmn_t && a[stmn[stmn_t]+l-1]>=a[i+l-1])S.modify(1,1,t,stmn[stmn_t-1]+1,stmn[stmn_t],a[stmn[stmn_t]+l-1]),--stmn_t;
		while(stmx_t && a[stmx[stmx_t]+l-1]<=a[i+l-1])S.modify(1,1,t,stmx[stmx_t-1]+1,stmx[stmx_t],-a[stmx[stmx_t]+l-1]),--stmx_t;
		stmn[++stmn_t]=stmx[++stmx_t]=i,S.modify(1,1,t,stmx[stmx_t-1]+1,stmx[stmx_t],a[stmx[stmx_t]+l-1]),S.modify(1,1,t,stmn[stmn_t-1]+1,stmn[stmn_t],-a[stmn[stmn_t]+l-1]);
		if(mp.count(a[i+l-1]))las=max(las,mp[a[i+l-1]]+1);
		mp[a[i+l-1]]=i,upd(ans,(aaa){S.find(1,1,t,las,k+i)+l-1,i+l-1});
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(!d)
	{
		for(int i=1;i<=n;++i)if(a[i]!=a[las])upd(ans,(aaa){las,i-1}),las=i;
		upd(ans,(aaa){las,n});
		return 0&printf("%d %d",ans.l,ans.r);
	}
	for(int i=1,j;i<=n;i=j)
	{
		for(j=i;j<=n && !((a[j]-a[i])%d);++j);
		solve(i,j-1);
	}
	return 0&printf("%d %d",ans.l,ans.r);
}