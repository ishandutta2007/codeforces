#include<bits/stdc++.h>
#define Mx 400000
#define LL long long
using namespace std;
int n,S_t=0;
LL ans=0;
int rt[400002],mn[400002],Rt[400002];
struct SegTree
{
	int cnt[8000002],lson[8000002],rson[8000002];
	LL sum[8000002],sum2[8000002];
	inline void pushup(int k,int ls,int rs)
	{
		cnt[k]=cnt[ls]+cnt[rs],sum[k]=sum[ls]+sum[rs],sum2[k]=sum2[ls]+sum2[rs]+sum[ls]*cnt[rs];
	}
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)return (void)(cnt[k]=1,sum[k]=l);
		int mid=((l+r)>>1);
		if(x<=mid)
		{
			if(!lson[k])lson[k]=(++S_t);
			modify(lson[k],l,mid,x);
		}
		else
		{
			if(!rson[k])rson[k]=(++S_t);
			modify(rson[k],mid+1,r,x);
		}
		pushup(k,lson[k],rson[k]);
	}
	inline int merge(int k,int k1,int l,int r)
	{
		if(!k || !k1)return (k|k1);
		int mid=((l+r)>>1);
		return lson[k]=merge(lson[k],lson[k1],l,mid),rson[k]=merge(rson[k],rson[k1],mid+1,r),pushup(k,lson[k],rson[k]),k;
	}
}S;
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void Link(int x,int y)
{
	getroot(x),getroot(y),mn[rt[y]]=min(mn[rt[y]],mn[rt[x]]),rt[rt[x]]=rt[y];
}
inline void add(int x,int o)
{
	getroot(x),ans+=(S.sum[Rt[rt[x]]]*mn[rt[x]]+S.sum2[Rt[rt[x]]])*o;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		if(rt[x])getroot(x),ans+=(LL)(rt[x]+1-x)*y,x=rt[x]+1;
		rt[x]=mn[x]=x,S.modify(Rt[x]=(++S_t),1,n,y);
		if(rt[x-1])add(x-1,-1),add(x,-1),Rt[x]=S.merge(Rt[x],Rt[x-1],1,n),Link(x-1,x),add(x,1);
		if(rt[x+1])add(x,-1),add(x+1,-1),Rt[rt[x+1]]=S.merge(Rt[rt[x+1]],Rt[x],1,n),Link(x,x+1),add(x,1);
		printf("%lld\n",ans);
	}
	return 0;
}