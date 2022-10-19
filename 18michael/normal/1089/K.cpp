#include<bits/stdc++.h>
#define Mx 1000000
#define LL long long
using namespace std;
int q,Test_num;
int X[300002],Y[300002];
char c;
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct aaa
{
	LL x,y;
};
inline aaa merge(aaa a,aaa b,int t)
{
	return (aaa){a.x+b.x,max(a.y+b.x+t,b.y)};
}
struct SegTree
{
	LL sum[4000002],wait[4000002];
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r){sum[k]+=d,wait[k]=sum[k];return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		sum[k]=sum[ls]+sum[rs],wait[k]=max(wait[ls]+sum[rs]-r+mid,wait[rs]);
	}
	inline aaa query(int k,int l,int r,int x)
	{
		if(r<=x)return (aaa){sum[k],wait[k]};
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)return query(ls,l,mid,x);
		return merge(query(ls,l,mid,x),query(rs,mid+1,r,x),-x+mid);
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
	read(q);
	for(int i=1;i<=q;++i)
	{
		do c=getchar();while(c!='+' && c!='-' && c!='?');
		scanf("%d",&X[i]);
		if(c=='+')scanf("%d",&Y[i]),S.modify(1,1,Mx,X[i],Y[i]);
		else if(c=='-')S.modify(1,1,Mx,X[X[i]],-Y[X[i]]);
		else printf("%lld\n",S.query(1,1,Mx,X[i]).y);
	}
	return 0;
}