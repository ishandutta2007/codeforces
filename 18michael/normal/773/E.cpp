#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define Mx 1000005
#define inf 0x3f3f3f3f
using namespace std;
int n;
typedef pair<int,int> P;P p;
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
	int sum[8000042],fir[8000042];
	inline void modify(int k,int l,int r,int x,int d)
	{
		sum[k]+=d,fir[k]+=(x==l? d:0);
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
	inline P find(int k,int l,int r,int d)
	{
		if(l==r)return P(l,d+sum[k]);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(-(d+sum[ls]+fir[rs])>=mid+1)return find(rs,mid+1,r,d+sum[ls]);
		return find(ls,l,mid,d);
	}
}S;
struct SegTree1
{
	int mn[8000042],laz[8000042];
	inline void build(int k,int l,int r)
	{
		mn[k]=inf+l;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
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
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return mn[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])mn[ls]+=laz[k],laz[ls]+=laz[k],mn[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return min(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),S1.build(1,-Mx,Mx);
	for(int i=1,x;i<=n;++i)
	{
		read(x),S1.modify(1,-Mx,Mx,-Mx,x-1,1);
		if(!S.query(1,-Mx,Mx,x,x))S1.modify(1,-Mx,Mx,x,x,-inf);
		S.modify(1,-Mx,Mx,x,1),p=S.find(1,-Mx,Mx,0),printf("%d\n",min(-p.second+S.query(1,-Mx,Mx,-p.second+1,Mx),S1.query(1,-Mx,Mx,p.first+1,Mx)));
	}
	return 0;
}