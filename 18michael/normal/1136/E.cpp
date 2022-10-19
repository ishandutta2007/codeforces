#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q;
char c;
LL t;
int a[100002],k[100002];
LL pre[100002];
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
	int laz[400002];
	inline void build(int k,int l,int r)
	{
		if(l==r){laz[k]=l;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1){laz[k]=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])laz[ls]=laz[rs]=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	}
	inline int query(int k,int l,int r,int x)
	{
		if(laz[k])return laz[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)return query(ls,l,mid,x);
		return query(rs,mid+1,r,x);
	}
}L,R;
struct SegTree1
{
	LL sum[400002],laz[400002];
	inline void build(int k,int l,int r)
	{
		if(l==r){sum[k]=a[l];return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),sum[k]=sum[ls]+sum[rs];
	}
	inline void modify(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1){laz[k]+=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],laz[rs]+=laz[k],sum[k]+=laz[k]*(r-l+1)+d*(r1-l1+1),laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k]+laz[k]*(r-l+1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],laz[rs]+=laz[k],sum[k]+=laz[k]*(r-l+1),laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),L.build(1,1,n),R.build(1,1,n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<n;++i)read(k[i]),pre[i]=pre[i-1]+k[i];
	S.build(1,1,n),read(q);
	for(int x,y,l,r;q--;)
	{
		do c=getchar();while(c!='+' && c!='s');
		read(x),read(y);
		if(c=='+')
		{
			if((l=L.query(1,1,n,x))<=(r=x-1))R.modify(1,1,n,l,r,r);
			t=S.query(1,1,n,x,x)+y;
			for(l=x;(r=R.query(1,1,n,l))<n && t+pre[r]-pre[x-1]>S.query(1,1,n,r+1,r+1);l=r+1)S.modify(1,1,n,l,r,t+pre[l-1]-pre[x-1]-S.query(1,1,n,l,l));
			S.modify(1,1,n,l,r,t+pre[l-1]-pre[x-1]-S.query(1,1,n,l,l)),L.modify(1,1,n,x,r,x),R.modify(1,1,n,x,r,r);
		}
		else printf("%lld\n",S.query(1,1,n,x,y));
	}
	return 0;
}