#include<cstdio>
#define Mx 29
int n,q;
int A[200002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[200002];
	inline void modify(int x,int d)
	{
		while(x<=n)sum[x]^=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res^=sum[x],x-=lowbit(x);
		return res;
	}
}B;
struct Vec
{
	int siz;
	int a[30];
	inline void init()
	{
		siz=0;
		for(int i=0;i<=Mx;++i)a[i]=0;
	}
	inline void ins(int x)
	{
		for(int i=Mx;~i;--i)
			if((x>>i)&1)
			{
				if(!a[i])
				{
					a[i]=x,++siz;
					break;
				}
				x^=a[i];
			}
	}
};
inline Vec merge(Vec a,Vec b)
{
	for(int i=0;i<=Mx;++i)if(a.a[i])b.ins(a.a[i]);
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
	Vec a[800002];
	inline void build(int k,int l,int r)
	{
		if(l==r){a[k].init(),a[k].ins(A[l]);return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),a[k]=merge(a[ls],a[rs]);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r){a[k].init(),a[k].ins(d);return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		a[k]=merge(a[ls],a[rs]);
	}
	inline Vec query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return a[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	for(int i=n;i;--i)A[i]^=A[i-1],B.modify(i,A[i]);
	S.build(1,1,n);
	for(int t,l,r,k;q--;)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			scanf("%d",&k),B.modify(l,k),A[l]^=k,S.modify(1,1,n,l,A[l]);
			if(r<n)B.modify(r+1,k),A[r+1]^=k,S.modify(1,1,n,r+1,A[r+1]);
		}
		else S.modify(1,1,n,l,B.query(l)),printf("%lld\n",(1LL<<S.query(1,1,n,l,r).siz)),S.modify(1,1,n,l,A[l]);
	}
	return 0;
}