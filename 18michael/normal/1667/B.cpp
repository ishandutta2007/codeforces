#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,Test_num,b_t;
int f[500002],id[500002],b[500002],mx[500002];
LL a[500002];
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
	int mx[2000012];
	inline void build(int k,int l,int r)
	{
		mx[k]=-inf;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		mx[k]=max(mx[k],d);
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
	}
	inline int query(int k,int l,int r,int x)
	{
		if(r<=x)return mx[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)return query(ls,l,mid,x);
		return max(mx[ls],query(rs,mid+1,r,x));
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),b_t=f[0]=id[0]=a[0]=0;
		for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1],id[i]=i;
		sort(id,id+n+1,cmp);
		for(int i=0;i<=n;++i)
		{
			if(!i || a[id[i]]!=a[id[i-1]])mx[++b_t]=-inf;
			b[id[i]]=b_t;
		}
		S.build(1,1,b_t),mx[b[0]]=max(mx[b[0]],f[0]),S.modify(1,1,b_t,b[0],f[0]);
		for(int i=1;i<=n;++i)
		{
			f[i]=max(f[i-1]+(a[i]>a[i-1]? 1:(a[i]<a[i-1]? -1:0)),mx[b[i]]);
			//printf("%d:%lld %d %d\n",i,a[i],b[i],f[i]);
			if(b[i]>1)f[i]=max(f[i],S.query(1,1,b_t,b[i]-1)+i);
			mx[b[i]]=max(mx[b[i]],f[i]),S.modify(1,1,b_t,b[i],f[i]-i);
			//printf("%d:%lld %d %d\n",i,a[i],b[i],f[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}