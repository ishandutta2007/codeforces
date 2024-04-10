#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q;
int a[100002];
LL p[100002],mn[400002],mx[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void build(int k,int l,int r)
{
	if(l==r){mn[k]=mx[k]=p[l];return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	build(ls,l,mid),build(rs,mid+1,r),mn[k]=min(mn[ls],mn[rs]),mx[k]=max(mx[ls],mx[rs]);
}
inline LL query_mn(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return mn[k];
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(r1<=mid)return query_mn(ls,l,mid,l1,r1);
	if(l1>mid)return query_mn(rs,mid+1,r,l1,r1);
	return min(query_mn(ls,l,mid,l1,mid),query_mn(rs,mid+1,r,mid+1,r1));
}
inline LL query_mx(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return mx[k];
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(r1<=mid)return query_mx(ls,l,mid,l1,r1);
	if(l1>mid)return query_mx(rs,mid+1,r,l1,r1);
	return max(query_mx(ls,l,mid,l1,mid),query_mx(rs,mid+1,r,mid+1,r1));
}
int main()
{
	read(n),read(q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),a[i]-=x,p[i]=p[i-1]+a[i];
	build(1,1,n);
	for(int l,r;q--;)
	{
		scanf("%d%d",&l,&r);
		if(p[r]!=p[l-1] || query_mx(1,1,n,l,r)>p[l-1])
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",p[l-1]-query_mn(1,1,n,l,r));
	}
	return 0;
}