#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,t,ans,Test_num;
int a[200002],to[200002];
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
	int mx[800002],laz[800002];
	inline void build(int k,int l,int r)
	{
		laz[k]=0;
		if(l==r)return (void)(mx[k]=l-1+(l&1)-inf);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),mx[k]=max(mx[ls],mx[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)return (void)(mx[k]+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])mx[ls]+=laz[k],laz[ls]+=laz[k],mx[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mx[k]=max(mx[ls],mx[rs]);
	}
}S;
inline void solve()
{
	scanf("%d",&n),S.build(1,1,n),ans=0,t=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[a[i]]=i;
	for(int i=1;i<=n;++i)
	{
		for(;t<=n && a[t]<=i;++t)S.modify(1,1,n,t,t,-inf);
		S.modify(1,1,n,to[i],to[i],inf),S.modify(1,1,n,1,to[i]-1,1),S.modify(1,1,n,to[i]+1,n,-1),ans=max(ans,S.mx[1]);
	}
	printf("%d\n",ans);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}