#include<bits/stdc++.h>
#define Mx 100000
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int q;
set<int> s[2];
set<int>::iterator it;
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
	int mx[400002],cnt[400002],tot[400002],se[400002],lazmx[400002],lazse[400002];
	LL sum[400002];
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
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l1>r1)return 0;
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S[2][2];
int main()
{
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<2;++j)S[i][j].build(1,1,Mx);
		for(int j=1;j<=Mx;++j)S[i][0].ins(1,1,Mx,j);
		S[i][0].add(1,1,Mx,1,Mx,inf);
	}
	for(int i=1;i<=Mx;++i)s[0].insert(i),s[1].insert(i);
	scanf("%d",&q);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			scanf("%d",&z),o=(z>0),z=abs(z),S[o][0].getmn(1,1,Mx,x,y-1,z),S[o][1].getmn(1,1,Mx,x,y-1,z);
			for(it=s[o].lower_bound(x);it!=s[o].end() && (*it)<y;it=s[o].erase(it))if(!s[o^1].count(*it))for(int i=0;i<2;++i)S[i][1].ins(1,1,Mx,*it),S[i][1].add(1,1,Mx,*it,*it,S[i][0].query(1,1,Mx,*it,*it));
		}
		else printf("%lld\n",S[0][1].query(1,1,Mx,x,y-1)+S[1][1].query(1,1,Mx,x,y-1));
	}
	return 0;
}