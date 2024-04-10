#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[200002];
struct aaa
{
	int f[6];
};
inline aaa merge(aaa a,aaa b)
{
	for(int i=0;i<=m;++i)b.f[i]=a.f[b.f[i]];
	return b;
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
	aaa t[800002],revt[800002];
	bool laz[800002];
	inline void pushup(int k,int ls,int rs)
	{
		t[k]=merge(t[ls],t[rs]),revt[k]=merge(revt[ls],revt[rs]);
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)
		{
			for(int i=0;i<=m;++i)revt[k].f[i]=min(i+1,m);
			for(int i=0;i<=m;++i)t[k].f[i]=(i<m? i+1:0);
			if(!(a[l]&1))swap(t[k],revt[k]);
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,ls,rs);
	}
	inline void rev(int k)
	{
		swap(t[k],revt[k]),laz[k]^=1;
	}
	inline void modify(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return rev(k);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])rev(ls),rev(rs),laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1);
		else modify(ls,l,mid,l1,mid),modify(rs,mid+1,r,mid+1,r1);
		pushup(k,ls,rs);
	}
	inline aaa query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return t[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])rev(ls),rev(rs),laz[k]=0;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
inline void read(int &x)
{
	char ch;
	do ch=getchar();while(ch<'0' || ch>'9');
	do x=(ch&1),ch=getchar();while(ch>='0' && ch<='9');
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)read(a[i]);
	S.build(1,1,n);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			read(z);
			if(z)S.modify(1,1,n,x,y);
		}
		else printf("%d\n",(!S.query(1,1,n,x,y).f[m])+1);
	}
	return 0;
}