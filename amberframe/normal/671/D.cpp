#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
typedef unsigned int u32;
#define pb push_back

const int maxn = 1200005;
const LL inf = 1ll<<50;

int ehead[maxn],ecnt;
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

int n,m;LL c[maxn],f[maxn];
int dfn[maxn],edfn[maxn],idx,loc[maxn];
vector<int> ins[maxn];
vector<int> del[maxn];

namespace ST
{
	#define ls rt<<1
	#define rs rt<<1|1
	LL minv[maxn],tag[maxn];
	void inc(int rt,LL w) {minv[rt]+=w;tag[rt]+=w;}
	void update(int rt)	{minv[rt]=min(minv[ls],minv[rs]);}
	void pushdown(int rt)
	{
		if (LL w=tag[rt]) {
			tag[rt]=0;inc(ls,w);inc(rs,w);
		}
	}
	void modify(int rt,int L,int R,int p,LL w)
	{
		if (L>=R) {minv[rt]=w;return ;}
		int mid=L+R>>1;pushdown(rt);
		if (p<=mid) modify(ls,L,mid,p,w);
		else modify(rs,mid+1,R,p,w);
		update(rt);
	}
	void increase(int rt,int L,int R,int l,int r,LL w)
	{
		if (L>=l&&R<=r) {inc(rt,w);return ;}
		int mid=L+R>>1;pushdown(rt);
		if (l<=mid) increase(ls,L,mid,l,r,w);
		if (r>mid) increase(rs,mid+1,R,l,r,w);
		update(rt);
	}
	LL query(int rt,int L,int R,int l,int r)
	{
		if (l>r) return inf;
		if (L>=l&&R<=r) return minv[rt];
		int mid=L+R>>1;pushdown(rt);LL res=inf;
		if (l<=mid) res=min(res,query(ls,L,mid,l,r));
		if (r>mid) res=min(res,query(rs,mid+1,R,l,r));
		return res;
	}
	void build(int rt,int L,int R)
	{
		minv[rt]=inf;
		if (L>=R) return ;
		int mid=L+R>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
}
using namespace ST ;

void dfs(int u,int fa)
{
	dfn[u]=idx+1;
	for (u32 i=0;i<ins[u].size();i++)
		loc[ins[u][i]]=++idx;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) dfs(v,u);
	edfn[u]=idx;
}
LL dp(int u,int fa)
{
	LL all=0;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) {
		all+=dp(v,u);all=min(all,2*inf);
	}
	if (u==1) return all<inf?all:-1;
	for (u32 i=0;i<ins[u].size();i++)
		modify(1,1,m,loc[ins[u][i]],c[ins[u][i]]+all);
	for (u32 i=0;i<del[u].size();i++)
		modify(1,1,m,loc[del[u][i]],inf);
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa)
		increase(1,1,m,dfn[v],edfn[v],all-f[v]);
	return f[u]=query(1,1,m,dfn[u],edfn[u]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("yusland.in","r",stdin);
		freopen("yusland.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int u,v,i=1;i<n;i++)
		scanf("%d %d",&u,&v),add(u,v);
	for (int u,v,i=1;i<=m;i++)
		scanf("%d %d %lld",&u,&v,&c[i]),
		ins[u].pb(i),del[v].pb(i);
	dfs(1,0);printf("%lld",dp(1,0));
	return 0;
}