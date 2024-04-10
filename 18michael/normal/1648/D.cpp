#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,q;
LL tmp,ans=-inf;
LL dp[500002];
LL a[3][500002];
struct aaa
{
	int l,r,k;
}s[500002];
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
	LL mx[2000008];
	inline void build(int k,int l,int r)
	{
		if(l==r){mx[k]=a[0][l+1]-a[1][l];return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),mx[k]=max(mx[ls],mx[rs]);
	}
	inline void modify(int k,int l,int r,int x,LL d)
	{
		mx[k]=max(mx[k],d);if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return mx[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return max(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S;
struct bbb
{
	LL mx1,mx2,mx;
};
inline bbb merge(bbb a,bbb b)
{
	return (bbb){max(a.mx1,b.mx1),max(a.mx2,b.mx2),max(max(a.mx,b.mx),a.mx1+b.mx2)};
}
struct SegTree1
{
	bbb t[2000008];
	inline void build1(int k,int l,int r)
	{
		if(l==r)
		{
			t[k]=(bbb){a[0][l]-a[1][l-1],a[1][r]-a[2][r-1],a[0][l]-a[1][l-1]+a[1][r]-a[2][r-1]};
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build1(ls,l,mid),build1(rs,mid+1,r),t[k]=merge(t[ls],t[rs]);
	}
	inline void build2(int k,int l,int r)
	{
		if(l==r)
		{
			t[k]=(bbb){dp[l]-a[1][l],a[1][r]-a[2][r-1],dp[l]-a[1][l]+a[1][r]-a[2][r-1]};
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build2(ls,l,mid),build2(rs,mid+1,r),t[k]=merge(t[ls],t[rs]);
	}
	inline bbb query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return t[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
	}
}S1,S2;
inline bool cmp(aaa a,aaa b)
{
	return a.r<b.r? 1:0;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<3;++i)for(int j=1;j<=n;++j)scanf("%lld",&a[i][j]),a[i][j]+=a[i][j-1];
	for(int i=1;i<=q;++i)scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].k);
	sort(s+1,s+q+1,cmp),S.build(1,0,n),S1.build1(1,1,n);
	for(int i=0;i<=n;++i)dp[i]=-inf;
	for(int i=1;i<=q;++i)
	{
		if((tmp=S.query(1,0,n,s[i].l-1,s[i].r-1))+a[1][s[i].r]-s[i].k>dp[s[i].r])S.modify(1,0,n,s[i].r,tmp-s[i].k),dp[s[i].r]=tmp+a[1][s[i].r]-s[i].k;
		ans=max(ans,S1.query(1,1,n,s[i].l,s[i].r).mx+a[2][n]-s[i].k);
	}
	S2.build2(1,0,n);
	for(int i=1;i<=q;++i)ans=max(ans,S2.query(1,0,n,s[i].l-1,s[i].r).mx+a[2][n]-s[i].k);
	return 0&printf("%lld",ans);
}