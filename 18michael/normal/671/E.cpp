#include<bits/stdc++.h>
#define Mx 16
#define eps 1e-9
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,K,st_t=0,ans=0,p;
LL t;
int st[100002];
LL a[100002],b[100002],c[100002],d[100002];
LL mx[100002][18];
inline LL getmx(int l,int r)
{
	int len=log2(r-l+1)+eps;
	return max(mx[l][len],mx[r-(1<<len)+1][len]);
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
	LL mx[400002],laz[400002];
	inline void build(int k,int l,int r)
	{
		mx[k]=-inf;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1)return (void)(mx[k]+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])mx[ls]+=laz[k],laz[ls]+=laz[k],mx[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mx[k]=max(mx[ls],mx[rs]);
	}
	inline int find(int k,int l,int r,int l1,int r1)
	{
		if(l==r)return l;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])mx[ls]+=laz[k],laz[ls]+=laz[k],mx[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(l1>mid || (r1>mid && getmx(mid+1,r1)+K>=max(t,mx[ls])))return t=max(t,mx[ls]),find(rs,mid+1,r,l1,r1);
		return find(ls,l,mid,l1,r1);
	}
}S;
inline int find(LL x)
{
	int l=1,r=st_t,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(c[st[mid]]<=x)r=mid-1;
		else l=mid+1;
	}
	return st[r]-1;
}
int main()
{
	scanf("%d%d",&n,&K),S.build(1,1,n),st[0]=n+1;
	for(int i=1;i<n;++i)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]),b[i]+=b[i-1];
	for(int i=1;i<=n;++i)c[i]=a[i-1]-b[i-1],mx[i][0]=d[i]=b[i]-a[i-1];
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
	for(int i=n;i;--i)
	{
		for(;st_t && c[i]>=c[st[st_t]];--st_t)if(st_t>1)S.modify(1,1,n,st[st_t-1]-1,n,c[st[st_t]]-c[st[st_t-1]]);
		st[++st_t]=i,S.modify(1,1,n,i,i,inf+d[i]);
		if(st_t>1)S.modify(1,1,n,st[st_t-1]-1,n,c[st[st_t-1]]-c[st[st_t]]);
		p=find(c[i]+K),t=-inf,ans=max(ans,S.find(1,1,n,i,p)-i+1);
	}
	return 0&printf("%d",ans);
}