#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100002];
typedef pair<int,int> P;
vector<P> vec;
struct aaa
{
	int val,l,r;
};
inline aaa getmx(aaa a,aaa b)
{
	return a.val>b.val? a:b;
}
inline aaa getmn(aaa a,aaa b)
{
	return a.val<b.val? a:b;
}
inline void Swap(aaa &a,aaa &b)
{
	swap(a,b),a.val=-a.val,b.val=-b.val;
}
struct bbb
{
	aaa mx,lmx,rmx;
	bool lcol,rcol;
	int l,r;
	int cnt[2],sum[2];
}tmp;
inline bbb merge(bbb a,bbb b)
{
	bbb c;
	c.lcol=a.lcol,c.rcol=b.rcol,c.l=a.l,c.r=b.r;
	c.cnt[0]=a.cnt[0]+b.cnt[0],c.cnt[1]=a.cnt[1]+b.cnt[1];
	c.sum[0]=a.sum[0]+b.sum[0],c.sum[1]=a.sum[1]+b.sum[1];
	c.lmx=a.lmx,c.rmx=b.rmx,c.mx=getmx(a.mx,b.mx);
	if(a.cnt[a.lcol]==a.r-a.l+1)c.lmx=getmx(c.lmx,(aaa){a.sum[a.lcol]+b.lmx.val,a.l,b.lmx.r});
	if(b.cnt[b.rcol]==b.r-b.l+1)c.rmx=getmx(c.rmx,(aaa){b.sum[b.rcol]+a.rmx.val,a.rmx.l,a.r});
	if(a.rcol==b.lcol)c.mx=getmx(c.mx,(aaa){a.rmx.val+b.lmx.val,a.rmx.l,b.lmx.r});
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
struct SegTree
{
	int len[400002];
	bool lcol[400002],rcol[400002],laz[400002];
	int cnt[400002][2],sum[400002][2];
	aaa lmx[400002],rmx[400002],lmn[400002],rmn[400002];
	aaa mx[400002][2],mn[400002][2];
	inline void init(int k,int l)
	{
		lcol[k]=rcol[k]=laz[k]=cnt[k][1]=sum[k][1]=0,cnt[k][0]=1,sum[k][0]=a[l];
		mx[k][0]=lmx[k]=getmx((aaa){a[l],l,l},(aaa){0,l,l-1});
		rmx[k]=getmx((aaa){a[l],l,l},(aaa){0,l+1,l});
		mx[k][1]=(aaa){0,l,l-1};
		mn[k][0]=lmn[k]=getmn((aaa){a[l],l,l},(aaa){0,l,l-1});
		rmn[k]=getmn((aaa){a[l],l,l},(aaa){0,l+1,l});
		mn[k][1]=(aaa){0,l,l-1};
	}
	inline void pushup(int k,int l,int r,int ls,int rs)
	{
		lcol[k]=lcol[ls],rcol[k]=rcol[rs];
		mx[k][0]=getmx(mx[ls][0],mx[rs][0]);
		mx[k][1]=getmx(mx[ls][1],mx[rs][1]);
		cnt[k][0]=cnt[ls][0]+cnt[rs][0];
		cnt[k][1]=cnt[ls][1]+cnt[rs][1];
		sum[k][0]=sum[ls][0]+sum[rs][0];
		sum[k][1]=sum[ls][1]+sum[rs][1];
		lmx[k]=lmx[ls],rmx[k]=rmx[rs],mx[k][0]=getmx(mx[ls][0],mx[rs][0]),mx[k][1]=getmx(mx[ls][1],mx[rs][1]);
		if(cnt[ls][lcol[ls]]==len[ls])lmx[k]=getmx(lmx[k],(aaa){sum[ls][lcol[ls]]+lmx[rs].val,l,lmx[rs].r});
		if(cnt[rs][rcol[rs]]==len[rs])rmx[k]=getmx(rmx[k],(aaa){sum[rs][rcol[rs]]+rmx[ls].val,rmx[ls].l,r});
		if(rcol[ls]==lcol[rs])mx[k][rcol[ls]]=getmx(mx[k][rcol[ls]],(aaa){rmx[ls].val+lmx[rs].val,rmx[ls].l,lmx[rs].r});
		lmn[k]=lmn[ls],rmn[k]=rmn[rs],mn[k][0]=getmn(mn[ls][0],mn[rs][0]),mn[k][1]=getmn(mn[ls][1],mn[rs][1]);
		if(cnt[ls][lcol[ls]]==len[ls])lmn[k]=getmn(lmn[k],(aaa){sum[ls][lcol[ls]]+lmn[rs].val,l,lmn[rs].r});
		if(cnt[rs][rcol[rs]]==len[rs])rmn[k]=getmn(rmn[k],(aaa){sum[rs][rcol[rs]]+rmn[ls].val,rmn[ls].l,r});
		if(rcol[ls]==lcol[rs])mn[k][rcol[ls]]=getmn(mn[k][rcol[ls]],(aaa){rmn[ls].val+lmn[rs].val,rmn[ls].l,lmn[rs].r});
	}
	inline void change(int k)
	{
		lcol[k]^=1,rcol[k]^=1,laz[k]^=1;
		Swap(mx[k][0],mn[k][1]);
		Swap(mx[k][1],mn[k][0]);
		swap(cnt[k][0],cnt[k][1]),swap(sum[k][0],sum[k][1]),sum[k][0]=-sum[k][0],sum[k][1]=-sum[k][1];
		Swap(lmx[k],lmn[k]);
		Swap(rmx[k],rmn[k]);
	}
	inline void pushdown(int k,int ls,int rs)
	{
		if(laz[k])change(ls),change(rs),laz[k]=0;
	}
	inline void build(int k,int l,int r)
	{
		len[k]=r-l+1;
		if(l==r)return init(k,l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),pushup(k,l,r,ls,rs);
	}
	inline void reverse(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return change(k);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)reverse(ls,l,mid,l1,r1);
		else if(l1>mid)reverse(rs,mid+1,r,l1,r1);
		else reverse(ls,l,mid,l1,mid),reverse(rs,mid+1,r,mid+1,r1);
		pushup(k,l,r,ls,rs);
	}
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r)return a[l]=d,init(k,l);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		pushup(k,l,r,ls,rs);
	}
	inline bbb query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return (bbb){getmx(mx[k][0],mx[k][1]),lmx[k],rmx[k],lcol[k],rcol[k],l,r,{cnt[k][0],cnt[k][1]},{sum[k][0],sum[k][1]}};
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	S.build(1,1,n),scanf("%d",&m);
	for(int o,x,y,z;m--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o)
		{
			for(scanf("%d",&z),ans=0;z--;)
			{
				tmp=S.query(1,1,n,x,y);
				if(tmp.mx.l>tmp.mx.r)break;
				ans+=tmp.mx.val,vec.push_back(P(tmp.mx.l,tmp.mx.r)),S.reverse(1,1,n,tmp.mx.l,tmp.mx.r);
			}
			for(printf("%d\n",ans);!vec.empty();vec.pop_back())S.reverse(1,1,n,vec.back().first,vec.back().second);
		}
		else S.modify(1,1,n,x,y);
	}
	return 0;
}