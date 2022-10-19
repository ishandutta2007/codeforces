#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,q;
LL tmp;
LL a[100002];
set<LL> s;
struct aaa
{
	LL mn;
	int pos;
}Tmp;
inline aaa merge(aaa a,aaa b)
{
	return a.mn<b.mn? a:b;
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
	aaa t[400002];
	LL lazadd[400002],lazcov[400002];
	inline LL get(LL x)
	{
		return x<inf/10? (*s.lower_bound(x))-x:inf;
	}
	inline void pushdown(int k,int ls,int rs,int l,int mid,int r)
	{
		if(lazcov[k])
		{
			if(l==mid)a[l]=lazcov[k];
			if(mid+1==r)a[r]=lazcov[k];
			lazcov[ls]=lazcov[rs]=lazcov[k],t[ls].mn=t[rs].mn=get(lazcov[k]),lazadd[ls]=lazadd[rs]=lazcov[k]=0;
		}
		if(lazadd[k])
		{
			if(l==mid)a[l]+=lazadd[k];
			if(mid+1==r)a[r]+=lazadd[k];
			lazadd[ls]+=lazadd[k],lazadd[rs]+=lazadd[k],t[ls].mn-=lazadd[k],t[rs].mn-=lazadd[k],lazadd[k]=0;
		}
	}
	inline void build(int k,int l,int r)
	{
		if(l==r)return (void)(t[k]=(aaa){get(a[l]),l});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),t[k]=merge(t[ls],t[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)
		{
			if(l==r)a[l]+=d;
			return (void)(t[k].mn-=d,lazadd[k]+=d);
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs,l,mid,r);
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		t[k]=merge(t[ls],t[rs]);
	}
	inline void cover(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)
		{
			if(l==r)a[l]=d;
			return (void)(t[k].mn=get(lazcov[k]=d),lazadd[k]=0);
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs,l,mid,r);
		if(r1<=mid)cover(ls,l,mid,l1,r1,d);
		else if(l1>mid)cover(rs,mid+1,r,l1,r1,d);
		else cover(ls,l,mid,l1,mid,d),cover(rs,mid+1,r,mid+1,r1,d);
		t[k]=merge(t[ls],t[rs]);
	}
	inline LL find(int k,int l,int r,int x)
	{
		if(l==r)return (t[k].mn<inf/10? l:0);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		LL res=0;
		pushdown(k,ls,rs,l,mid,r);
		if(x<=mid && t[ls].mn<inf/10)res=find(ls,l,mid,x);
		if(!res)res=find(rs,mid+1,r,x);
		return res;
	}
	inline void update(int k,int l,int r,int x)
	{
		if(l==r)return (void)(t[k]=(aaa){get(a[l]),l});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs,l,mid,r);
		if(x<=mid)update(ls,l,mid,x);
		else update(rs,mid+1,r,x);
		t[k]=merge(t[ls],t[rs]);
	}
	inline LL query(int k,int l,int r,int x)
	{
		if(l==r)return a[l];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs,l,mid,r);
		if(x<=mid)return query(ls,l,mid,x);
		return query(rs,mid+1,r,x);
	}
	inline aaa queryt(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return t[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs,l,mid,r);
		if(r1<=mid)return queryt(ls,l,mid,l1,r1);
		if(l1>mid)return queryt(rs,mid+1,r,l1,r1);
		return merge(queryt(ls,l,mid,l1,r1),queryt(rs,mid+1,r,l1,r1));
	}
}S;
int main()
{
	s.insert(tmp=1);
	for(int i=1;i<=9;++i)s.insert(tmp*=42);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	S.build(1,1,n);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d",&o,&x);
		if(o==1)printf("%lld\n",S.query(1,1,n,S.find(1,1,n,x)));
		else if(o==2)
		{
			scanf("%d%d",&y,&z);
			if(x>1)S.cover(1,1,n,x-1,x-1,S.query(1,1,n,S.find(1,1,n,x-1)));
			S.cover(1,1,n,x,y-1,inf),S.cover(1,1,n,y,y,z);
		}
		else
		{
			for(scanf("%d%d",&y,&z);;)
			{
				if(x>1)S.cover(1,1,n,x-1,x-1,S.query(1,1,n,S.find(1,1,n,x-1)));
				for(S.cover(1,1,n,y,y,S.query(1,1,n,S.find(1,1,n,y))),S.modify(1,1,n,x,y,z);(Tmp=S.queryt(1,1,n,x,y)).mn<0;)S.update(1,1,n,Tmp.pos);
				if(Tmp.mn>0)break;
			}
		}
	}
	return 0;
}