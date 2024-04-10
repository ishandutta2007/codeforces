#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k,x,ans=0;
LL a[200002],arr[800002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL _pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c*=c;
	if(b&1)c*=a;
	return c;
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
	if(l==r)return (void)(arr[k]=a[l]);
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	build(ls,l,mid),build(rs,mid+1,r),arr[k]=(arr[ls]|arr[rs]);
}
inline void modify(int k,int l,int r,int x)
{
	if(l==r)return (void)(arr[k]=a[x]);
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	if(x<=mid)modify(ls,l,mid,x);
	else modify(rs,mid+1,r,x);
	arr[k]=(arr[ls]|arr[rs]);
}
int main()
{
	read(n),read(k),read(x),x=_pow(x,k);
	for(int i=1;i<=n;++i)read(a[i]);
	build(1,1,n);
	for(int i=1;i<=n;++i)a[i]*=x,modify(1,1,n,i),ans=max(ans,arr[1]),a[i]/=x,modify(1,1,n,i);
	printf("%lld",ans);
	return 0;
}