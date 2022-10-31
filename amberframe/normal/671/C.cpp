#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
#define pb push_back

const int maxn = 800005;
const int inf = 1<<30;
const int N = 2e5;
LL ans;int n;
int min1[maxn],min2[maxn];
int max1[maxn],max2[maxn];

void insert(int &mi1,int &mi2,int &mx1,int &mx2,int x)
{
	if (x==-inf||x==inf) return ;
	(mi1>x)?(mi2=mi1,mi1=x):(mi2>x&&mi1!=x?mi2=x:0);
	(mx1<x)?(mx2=mx1,mx1=x):(mx2<x&&mx1!=x?mx2=x:0);
}

namespace ST {
	#define ls rt<<1
	#define rs rt<<1|1
	int minp[maxn],tag[maxn],sz[maxn];LL sum[maxn];
	void assign(int rt,int w)
	{
		tag[rt]=minp[rt]=w;
		sum[rt]=(LL)w*sz[rt];
	}
	void pushdown(int rt)
	{
		if (tag[rt]!=-1) {
			assign(ls,tag[rt]);
			assign(rs,tag[rt]);
			tag[rt]=-1;
		}
	}
	void update(int rt)
	{
		sum[rt]=sum[ls]+sum[rs];
		minp[rt]=minp[ls];
	}
	void build(int rt,int L,int R)
	{
		sz[rt]=R-L+1;tag[rt]=-1;
		if (L>=R) {
			sum[rt]=minp[rt]=L;return ;
		}
		int mid=L+R>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(rt);
	}
	void assign(int rt,int L,int R,int l,int r,int w)
	{
		if (l>r) return ;
		if (L>=l&&R<=r) {
			assign(rt,w);return ;
		}
		int mid=L+R>>1;pushdown(rt);
		if (l<=mid) assign(ls,L,mid,l,r,w);
		if (r>mid) assign(rs,mid+1,R,l,r,w);
		update(rt);
	}
	int findpos(int rt,int L,int R,int w)
	{
		if (L>=R) return minp[rt]<w?L:L-1;
		int mid=L+R>>1;pushdown(rt);
		if (minp[rs]<w) return findpos(rs,mid+1,R,w);
		else return findpos(ls,L,mid,w);
	}
}
using namespace ST ;

LL f[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("array.in","r",stdin);
		freopen("array.out","w",stdout);
	#endif
	for (int i=1;i<=N;i++)
		max1[i]=max2[i]=-inf,
		min1[i]=min2[i]=inf;
	scanf("%d",&n);f[N]=(LL)n*(n+1)/2;
	for (int x,i=1;i<=n;i++)
		scanf("%d",&x),insert(min1[x],min2[x],max1[x],max2[x],i);
	build(1,1,n);
	for (int i=N;i>=1;i--)
	{
		int mx1=max1[i],mx2=max2[i];
		int mi1=min1[i],mi2=min2[i];
		for (int j=i<<1;j<=N;j+=i)
			insert(mi1,mi2,mx1,mx2,max1[j]),
			insert(mi1,mi2,mx1,mx2,max2[j]),
			insert(mi1,mi2,mx1,mx2,min1[j]),
			insert(mi1,mi2,mx1,mx2,min2[j]);
		if (mi1!=inf&&mi1!=mx1) {
			int _1=findpos(1,1,n,mx1);
			assign(1,1,n,mi1+1,min(_1,mi2),mx1);
			int _2=findpos(1,1,n,mx2);
			assign(1,1,n,1,min(_2,mi1),mx2);
			assign(1,1,n,mi2+1,n,n+1);
		}
		f[i-1]=(LL)n*(n+1)-sum[1];
	}
	for (int i=N;i>=1;i--)
		ans+=(f[i]-f[i-1])*i;
	printf("%lld",ans);
	return 0;
}