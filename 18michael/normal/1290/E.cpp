#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[150002],to[150002];
LL ans[150002];
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
	int mx[600002],cnt[600002],tot[600002],se[600002],lazmx[600002],lazse[600002];
	LL sum[600002];
	inline void pushup(int k,int ls,int rs)
	{
		sum[k]=sum[ls]+sum[rs];
		if(mx[ls]<mx[rs])swap(ls,rs);
		mx[k]=mx[ls],cnt[k]=cnt[ls];
		if(mx[ls]==mx[rs])cnt[k]+=cnt[rs],se[k]=max(se[ls],se[rs]);
		else se[k]=max(se[ls],mx[rs]);
	}
	inline void addmx(int k,int d)
	{
		if(d && cnt[k])sum[k]+=(LL)d*cnt[k],mx[k]+=d,lazmx[k]+=d;
	}
	inline void addse(int k,int d)
	{
		if(d)sum[k]+=(LL)d*(tot[k]-cnt[k]),se[k]+=d,lazse[k]+=d;
	}
	inline void pushdown(int k,int ls,int rs)
	{
		if(mx[ls]==mx[k]-lazmx[k])addmx(ls,lazmx[k]);
		else addmx(ls,lazse[k]);
		if(mx[rs]==mx[k]-lazmx[k])addmx(rs,lazmx[k]);
		else addmx(rs,lazse[k]);
		addse(ls,lazse[k]),addse(rs,lazse[k]),lazmx[k]=lazse[k]=0;
	}
	inline void build(int k,int l,int r)
	{
		lazmx[k]=lazse[k]=tot[k]=0;
		if(l==r)return (void)(mx[k]=sum[k]=cnt[k]=0,se[k]=-inf);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,ls,rs);
	}
	inline void add(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)return addmx(k,d),addse(k,d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)add(ls,l,mid,l1,r1,d);
		else if(l1>mid)add(rs,mid+1,r,l1,r1,d);
		else add(ls,l,mid,l1,mid,d),add(rs,mid+1,r,mid+1,r1,d);
		pushup(k,ls,rs);
	}
	inline void getmn(int k,int l,int r,int l1,int r1,int d)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)
		{
			if(mx[k]<=d)return ;
			if(se[k]<d)return addmx(k,d-mx[k]);
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)getmn(ls,l,mid,l1,r1,d);
		else if(l1>mid)getmn(rs,mid+1,r,l1,r1,d);
		else getmn(ls,l,mid,l1,mid,d),getmn(rs,mid+1,r,mid+1,r1,d);
		pushup(k,ls,rs);
	}
	inline void ins(int k,int l,int r,int x)
	{
		if(l==r)return (void)(cnt[k]=tot[k]=1);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(x<=mid)ins(ls,l,mid,x);
		else ins(rs,mid+1,r,x);
		tot[k]=tot[ls]+tot[rs],pushup(k,ls,rs);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l1>r1)return 0;
		if(l>=l1 && r<=r1)return tot[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S;
inline void solve()
{
	S.build(1,1,n);
	for(int i=1;i<=n;++i)S.ins(1,1,n,to[i]),S.getmn(1,1,n,1,to[i]-1,S.query(1,1,n,1,to[i])),S.add(1,1,n,to[i],to[i],i+1),S.add(1,1,n,to[i]+1,n,1),ans[i]+=S.sum[1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[a[i]]=i;
	solve();
	for(int i=1;i<n+1-i;++i)swap(a[i],a[n+1-i]),swap(to[a[i]],to[a[n+1-i]]);
	solve();
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]-(LL)i*(i+2));
	return 0;
}