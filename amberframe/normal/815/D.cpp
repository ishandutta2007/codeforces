#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
typedef long long LL;
const int maxn = 500005*4;

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
		minp[rt]=min(minp[ls],minp[rs]);
	}
	void build(int rt,int L,int R)
	{
		sz[rt]=R-L+1;tag[rt]=-1;
		if (L>=R) return ;
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
		if (L>=R) return minp[rt]<w?L:L+1;
		int mid=L+R>>1;pushdown(rt);
		if (minp[ls]<w) return findpos(ls,L,mid,w);
		else return findpos(rs,mid+1,R,w);
	}
	LL query(int rt,int L,int R,int l,int r)
	{
		if (L>=l&&R<=r) return sum[rt];
		int mid=L+R>>1;pushdown(rt);
		LL res=0;
		if (l<=mid) res+=query(ls,L,mid,l,r);
		if (r>mid) res+=query(rs,mid+1,R,l,r);
		return res; 
	}
	void dfs(int rt,int L,int R)
	{
		if (L>=R) {
			cerr<<minp[rt]<<" ";return ;
		}
		int mid=L+R>>1;pushdown(rt);
		dfs(ls,L,mid);dfs(rs,mid+1,R);
	}
}

using namespace ST;
#define pb push_back
struct node {int i,j,k;};
vector<node> ins[maxn];
int maxj[maxn],maxk[maxn];
LL ans=0;int n,p,q,r;

void modify(int j,int k)
{
	int t=findpos(1,1,q,k);
	assign(1,1,q,t,j,k);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("cards.in","r",stdin);
		//freopen("cards.out","w",stdout);
	#endif
	scanf("%d %d %d %d",&n,&p,&q,&r);
	for (int x,y,z,i=1;i<=n;i++)
		scanf("%d %d %d",&x,&y,&z),
		ins[x].pb((node){x,y,z}),
		maxj[x]=max(maxj[x],y),
		maxk[x]=max(maxk[x],z);
	for (int i=p-1;i>=1;i--) maxj[i]=max(maxj[i],maxj[i+1]);
	for (int i=p-1;i>=1;i--) maxk[i]=max(maxk[i],maxk[i+1]);
	
	build(1,1,q);
	for (int i=1;i<=p;i++)
	{
		int a=maxj[i],b=maxk[i];
		if (a<q) {
			
			int t=findpos(1,1,q,b);t=max(a+1,t);
			if (t<=q) ans+=(LL)(q-t+1)*(r-b);
			if (a+1<t) ans+=(LL)(t-a-1)*r-query(1,1,q,a+1,t-1); 
		}
		int siz=ins[i].size();
		for (int j=0;j<siz;j++)
			modify(ins[i][j].j,ins[i][j].k);
	}
	printf("%lld",ans);
	return 0;
}