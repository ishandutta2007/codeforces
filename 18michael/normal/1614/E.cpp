#include<bits/stdc++.h>
#define LL long long
#define Mx 1000000000
#define mod 1000000001
using namespace std;
int n,t,S_t=0,lastans=0;
struct SegTree
{
	int lson[40000002],rson[40000002],laz[40000002],mx[40000002];
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1){laz[k]+=d;return ;}
		int mid=((l+r)>>1);
		if(!lson[k])lson[k]=(++S_t);
		if(!rson[k])rson[k]=(++S_t);
		laz[lson[k]]+=laz[k],laz[rson[k]]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(lson[k],l,mid,l1,r1,d);
		else if(l1>mid)modify(rson[k],mid+1,r,l1,r1,d);
		else modify(lson[k],l,mid,l1,mid,d),modify(rson[k],mid+1,r,mid+1,r1,d);
		mx[k]=mx[rson[k]]+laz[rson[k]];
	}
	inline int query(int k,int l,int r,int x)
	{
		if(l==r)return mx[k]+laz[k];
		int mid=((l+r)>>1);
		if(!lson[k])lson[k]=(++S_t);
		if(!rson[k])rson[k]=(++S_t);
		laz[lson[k]]+=laz[k],laz[rson[k]]+=laz[k],mx[k]+=laz[k],laz[k]=0;
		if(x<=mid)return query(lson[k],l,mid,x);
		return query(rson[k],mid+1,r,x);
	}
	inline int find(int k,int l,int r,int x)
	{
		if(l==r)return l+(l+mx[k]+laz[k]<x);
		int mid=((l+r)>>1);
		if(!lson[k])lson[k]=(++S_t);
		if(!rson[k])rson[k]=(++S_t);
		laz[lson[k]]+=laz[k],laz[rson[k]]+=laz[k],mx[k]+=laz[k],laz[k]=0;
		if(mid+mx[lson[k]]+laz[lson[k]]>=x)return find(lson[k],l,mid,x);
		return find(rson[k],mid+1,r,x);
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
	read(n);
	for(int i=1,k,l,r;i<=n;++i)
	{
		read(t),read(k),l=S.find(0,0,Mx,t)-1,r=S.find(0,0,Mx,t+1),S.modify(0,0,Mx,0,l,1),S.modify(0,0,Mx,r,Mx,-1);
		for(int j=1,x;j<=k;++j)read(x),x=(x+lastans)%mod,printf("%d\n",lastans=x+S.query(0,0,Mx,x));
	}
	return 0;
}