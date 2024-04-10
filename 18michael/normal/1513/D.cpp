#include<bits/stdc++.h>
#define Mx 17
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,n1,p,l,r,mid,L,R,Test_num;
int f[200002][18];
struct aaa
{
	int mx,mx2,laz;
	LL tim,sum;
}arr[800002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
inline int GCD(int l,int r)
{
	int len=r-l+1,lg=log(r-l+1)/log(2);
	return gcd(f[l][lg],f[r-(1<<lg)+1][lg]);
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void upd(int k)
{
	int ls=lson(k),rs=rson(k);arr[k].sum=arr[ls].sum+arr[rs].sum;
	if(arr[ls].mx==arr[rs].mx)arr[k].mx=arr[ls].mx,arr[k].tim=arr[ls].tim+arr[rs].tim,arr[k].mx2=max(arr[ls].mx2,arr[rs].mx2);
	else
	{
		if(arr[ls].mx<arr[rs].mx)swap(ls,rs);
		arr[k].mx=arr[ls].mx,arr[k].tim=arr[ls].tim,arr[k].mx2=max(arr[ls].mx2,arr[rs].mx);
	}
}
inline void build(int k,int l,int r)
{
	if(l==r)
	{
		arr[k]=(aaa){p,-inf,inf,1,p};
		return ;
	}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	build(ls,l,mid),build(rs,mid+1,r),arr[k].laz=inf,upd(k);
}
inline void modify(int k,int l,int r,int l1,int r1,int x)
{
	if(arr[k].mx<=x)return ;
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(l>=l1 && r<=r1)
	{
		arr[k].laz=min(arr[k].laz,x);
		if(arr[k].mx2<x)
		{
			arr[k].sum-=(arr[k].mx-x)*arr[k].tim,arr[k].laz=min(arr[k].laz,x),arr[k].mx=x;
			return ;
		}
		x=min(x,arr[k].laz),modify(ls,l,mid,l1,mid,x),modify(rs,mid+1,r,mid+1,r1,x);
	}
	else
	{
		modify(ls,l,mid,l,mid,arr[k].laz),modify(rs,mid+1,r,mid+1,r,arr[k].laz);
		if(r1<=mid)modify(ls,l,mid,l1,r1,x);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,x);
		else modify(ls,l,mid,l1,mid,x),modify(rs,mid+1,r,mid+1,r1,x);
	}
	upd(k);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(p),n1=n-1;
		for(int i=1;i<=n;++i)read(f[i][0]);
		build(1,1,n1);
		for(int i=1,k=1;i<=Mx;++i,k<<=1)
			for(int j=1;j+2*k-1<=n;++j)
				f[j][i]=gcd(f[j][i-1],f[j+k][i-1]);
		for(int i=1;i<=n;++i)
		{
			l=1,r=i-1;
			while(l<=r)
			{
				mid=((l+r)>>1);
				if(GCD(mid,i)!=f[i][0])l=mid+1;
				else r=mid-1;
			}
			L=l,l=i+1,r=n;
			while(l<=r)
			{
				mid=((l+r)>>1);
				if(GCD(i,mid)!=f[i][0])r=mid-1;
				else l=mid+1;
			}
			R=r;
			if(R>L)modify(1,1,n1,L,R-1,f[i][0]);
		}
		printf("%lld\n",arr[1].sum);
	}
	return 0;
}