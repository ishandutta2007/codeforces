#include<bits/stdc++.h>
#define Mx 300000
#define LL long long
using namespace std;
int n;
LL ans=0,res=0;
LL a[300002];
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
struct SegTree
{
	LL arr[1200002],laz[1200002];
	inline void modify(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1){laz[k]+=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],laz[rs]+=laz[k],arr[k]+=laz[k]*(r-l+1)+d*(r1-l1+1),laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return arr[k]+laz[k]*(r-l+1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		laz[ls]+=laz[k],laz[rs]+=laz[k],arr[k]+=laz[k]*(r-l+1),laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S1,S2;
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)
	{
		ans+=res-S1.query(1,1,Mx,a[i],a[i])+a[i]*(i-1);
		for(int j=1;j*a[i]<=Mx;++j)ans-=S2.query(1,1,Mx,j*a[i],min((j+1)*a[i]-1,(LL)(Mx)))*j*a[i];
		printf("%lld ",ans),res+=a[i],S2.modify(1,1,Mx,a[i],a[i],1);
		for(int j=1;j*a[i]<=Mx;++j)S1.modify(1,1,Mx,j*a[i],min((j+1)*a[i]-1,(LL)(Mx)),j*a[i]);
	}
	return 0;
}