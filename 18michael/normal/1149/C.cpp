#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[200002];
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
	int sum[800002],sufmn[800002],premx[800002],lmx[800002],rmx[800002],lrmx[800002],mx[800002];
	inline void pushup(int k,int ls,int rs)
	{
		sum[k]=sum[ls]+sum[rs];
		sufmn[k]=min(sufmn[ls]+sum[rs],sufmn[rs]);
		premx[k]=max(premx[ls],sum[ls]+premx[rs]);
		lmx[k]=max(max(lmx[ls],lmx[rs]-sum[ls]),lrmx[ls]+premx[rs]);
		rmx[k]=max(max(rmx[rs],rmx[ls]+sum[rs]),lrmx[rs]-sufmn[ls]);
		lrmx[k]=max(lrmx[ls]+sum[rs],lrmx[rs]-sum[ls]);
		mx[k]=max(max(mx[ls],mx[rs]),max(rmx[ls]+premx[rs],lmx[rs]-sufmn[ls]));
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(sum[k]=(s[l]=='('? 1:-1),sufmn[k]=min(sum[k],0),premx[k]=max(sum[k],0),lmx[k]=rmx[k]=mx[k]=lrmx[k]=1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,ls,rs);
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return (void)(sum[k]=(s[l]=='('? 1:-1),sufmn[k]=min(sum[k],0),premx[k]=max(sum[k],0));
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		pushup(k,ls,rs);
	}
}S;
int main()
{
	scanf("%d%d%s",&n,&q,s+1),n=(n-1)<<1,S.build(1,1,n),printf("%d\n",S.mx[1]);
	for(int x,y;q--;printf("%d\n",S.mx[1]))scanf("%d%d",&x,&y),swap(s[x],s[y]),S.modify(1,1,n,x),S.modify(1,1,n,y);
	return 0;
}