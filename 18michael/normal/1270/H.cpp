#include<bits/stdc++.h>
#define Mx 1000000
#define inf 0x3f3f3f3f
using namespace std;
int n,q;
int a[500012];
struct aaa
{
	int mn,sum;
};
inline aaa merge(aaa a,aaa b)
{
	if(a.mn<b.mn)return a;
	if(a.mn>b.mn)return b;
	return (aaa){a.mn,a.sum+b.sum};
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
	int laz[4000002];
	aaa a[4000002];
	inline void modifysum(int k,int l,int r,int x,int d)
	{
		if(l==r)return (void)(a[k].sum+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])a[ls].mn+=laz[k],laz[ls]+=laz[k],a[rs].mn+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(x<=mid)modifysum(ls,l,mid,x,d);
		else modifysum(rs,mid+1,r,x,d);
		a[k]=merge(a[ls],a[rs]);
	}
	inline void modifymn(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)return (void)(a[k].mn+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])a[ls].mn+=laz[k],laz[ls]+=laz[k],a[rs].mn+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modifymn(ls,l,mid,l1,r1,d);
		else if(l1>mid)modifymn(rs,mid+1,r,l1,r1,d);
		else modifymn(ls,l,mid,l1,mid,d),modifymn(rs,mid+1,r,mid+1,r1,d);
		a[k]=merge(a[ls],a[rs]);
	}
}S;
inline void add(int x,int o)
{
	if(x>1 && x<n)S.modifysum(1,1,Mx,a[x],o);
	if(a[x]<a[x-1])S.modifymn(1,1,Mx,max(a[x],1),min(a[x-1]-1,Mx),o);
}
int main()
{
	scanf("%d%d",&n,&q),a[1]=inf,a[n+2]=-inf;
	for(int i=1;i<=n;++i)scanf("%d",&a[i+1]);
	for(int i=(n+=2);i>1;--i)add(i,1);
	for(int x,y;q--;)scanf("%d%d",&x,&y),++x,add(x,-1),add(x+1,-1),a[x]=y,add(x,1),add(x+1,1),printf("%d\n",S.a[1].mn==1? S.a[1].sum:0);
	return 0;
}