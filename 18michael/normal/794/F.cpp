#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,q,S_t=0;
LL ans;
int rt[10];
typedef pair<int,int> P;P p;
struct SegTree
{
	LL sum[30000002];
	int lson[30000002],rson[30000002];
	inline void modify(int k,int l,int r,int x,int d)
	{
		sum[k]+=d;
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)
		{
			if(!lson[k])lson[k]=(++S_t);
			modify(lson[k],l,mid,x,d);
		}
		else
		{
			if(!rson[k])rson[k]=(++S_t);
			modify(rson[k],mid+1,r,x,d);
		}
	}
	inline int merge(int x,int y,int l,int r)
	{
		if(!x || !y)return (x|y);
		if(l==r)return sum[x]+=sum[y],x;
		int mid=((l+r)>>1);
		return sum[x]=sum[lson[x]=merge(lson[x],lson[y],l,mid)]+sum[rson[x]=merge(rson[x],rson[y],mid+1,r)],x;
	}
	inline P split(int k,int l,int r,int l1,int r1)
	{
		if(!k)return P(0,0);
		if(l>=l1 && r<=r1)return P(k,0);
		int mid=((l+r)>>1),k1=(++S_t);P p;
		if(l1<=mid)p=split(lson[k],l,mid,l1,r1),lson[k]=p.second,lson[k1]=p.first;
		if(r1>mid)p=split(rson[k],mid+1,r,l1,r1),rson[k]=p.second,rson[k1]=p.first;
		return sum[k]=sum[lson[k]]+sum[rson[k]],sum[k1]=sum[lson[k1]]+sum[rson[k1]],P(k1,k);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(!k)return 0;
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],mid+1,r,l1,r1);
		return query(lson[k],l,mid,l1,mid)+query(rson[k],mid+1,r,mid+1,r1);
	}
}S;
int main()
{
	for(int i=0;i<10;++i)rt[i]=(++S_t);
	scanf("%d%d",&n,&q);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		for(int j=0,res=1;x;++j,x/=10,res*=10)S.modify(rt[x%10],1,n,i,res);
	}
	for(int o,x,y,z,w;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)scanf("%d%d",&z,&w),p=S.split(rt[z],1,n,x,y),rt[z]=p.second,rt[w]=S.merge(rt[w],p.first,1,n);
		else
		{
			ans=0;
			for(int i=0;i<10;++i)ans+=S.query(rt[i],1,n,x,y)*i;
			printf("%lld\n",ans);
		}
	}
	return 0;
}