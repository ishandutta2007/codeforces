#include<cstdio>
#define LL long long
int n,st1_t=0,st2_t=0;
LL ans=0;
int a[300002],st1[300002],st2[300002];
inline int min(int x,int y)
{
	return x<y? x:y;
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
	int mn[1200002],num[1200002],laz[1200002];
	inline void build(int k,int l,int r)
	{
		mn[k]=laz[k]=0,num[k]=r-l+1;
		if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)
		{
			mn[k]+=d,laz[k]+=d;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		mn[ls]+=laz[k],laz[ls]+=laz[k],mn[rs]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
		mn[k]=min(mn[ls],mn[rs]),num[k]=(mn[ls]==mn[k]? num[ls]:0)+(mn[rs]==mn[k]? num[rs]:0);
	}
}S;
int main()
{
	scanf("%d",&n),st1[0]=st2[0]=0,S.build(1,1,n);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),a[x]=y;
	for(int i=1;i<=n;++i)
	{
		while(st1_t && a[i]<a[st1[st1_t]])S.modify(1,1,n,st1[st1_t-1]+1,st1[st1_t],a[st1[st1_t]]-a[i]),--st1_t;
		while(st2_t && a[i]>a[st2[st2_t]])S.modify(1,1,n,st2[st2_t-1]+1,st2[st2_t],a[i]-a[st2[st2_t]]),--st2_t;
		S.modify(1,1,n,1,i,-1),st1[++st1_t]=st2[++st2_t]=i,ans+=S.num[1];
	}
	return 0&printf("%lld",ans);
}