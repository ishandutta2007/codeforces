#include<bits/stdc++.h>
using namespace std;
int n,m,q,l,r;
char c[1000002];
bool ck[1000002];
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline bool check(int x)
{
	for(int i=2;i<=n;++i)if(c[num(i,x)]=='X' && c[num(i-1,x+1)]=='X')return 0;
	return 1;
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
	bool ok[4000002];
	inline void build(int k,int l,int r)
	{
		if(l==r){ok[k]=1;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),ok[k]=(ok[ls] && ok[rs] && ck[mid]);
	}
	inline bool query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return ok[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return (ck[mid] && query(ls,l,mid,l1,mid) && query(rs,mid+1,r,mid+1,r1));
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
	read(n),read(m);
	for(int i=1;i<=n*m;++i)do c[i]=getchar();while(c[i]!='.' && c[i]!='X');
	for(int i=1;i<m;++i)ck[i]=check(i);S.build(1,1,m),read(q);
	while(q--)read(l),read(r),puts(S.query(1,1,m,l,r)? "YES":"NO");
	return 0;
}