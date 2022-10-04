#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
const int MAXN=500005;
const ll INF=1ll<<52;

int n,m;
vector<pii> G[MAXN];
struct Data{int l,r,id;};
vector<Data> b[MAXN];

ll dis[MAXN];int size[MAXN];
ll ans[MAXN],sum[MAXN<<2|1],lazy[MAXN<<2|1];
inline void pushdown(int id)
{
	if(!lazy[id])return;
	lazy[id<<1]+=lazy[id];
	lazy[id<<1|1]+=lazy[id];
	sum[id]+=lazy[id];
	lazy[id]=0;
}
inline void update(int id)
	{sum[id]=min(sum[id<<1]+lazy[id<<1],sum[id<<1|1]+lazy[id<<1|1]);}
void build(int id,int l,int r)
{
	if(l==r){sum[id]=dis[l];return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
ll query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return sum[id]+lazy[id];
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr){lazy[id]+=c;return;}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else {modify(id<<1,l,mid,ql,mid,c);modify(id<<1|1,mid+1,r,mid+1,qr,c);}
	update(id);
}

void getdis(int u)
{
	int v,c;
	bool flag=0;
	size[u]=1;
	for(int i=0;i<G[u].size();++i)
	{
		v=G[u][i].first;c=G[u][i].second;
		flag=1;
		dis[v]=dis[u]+c;
		getdis(v);
		size[u]+=size[v];
	}
	if(flag)dis[u]=INF;
}
void dfs(int u)
{
	for(int i=0;i<b[u].size();++i)
		ans[b[u][i].id]=query(1,1,n,b[u][i].l,b[u][i].r);
	int v,c;
	for(int i=0;i<G[u].size();++i)
	{
		v=G[u][i].first;c=G[u][i].second;
		modify(1,1,n,v,v+size[v]-1,-c);
		if(v>1)modify(1,1,n,1,v-1,c);
		if(v+size[v]<=n)modify(1,1,n,v+size[v],n,c);
		dfs(v);
		modify(1,1,n,v,v+size[v]-1,c);
		if(v>1)modify(1,1,n,1,v-1,-c);
		if(v+size[v]<=n)modify(1,1,n,v+size[v],n,-c);
	}
}

int main()
{
    int u,c;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
    	scanf("%d%d",&u,&c);
    	G[u].pb(mp(i,c));
    }
    for(int i=1;i<=n;i++)
    	if(G[i].size())
    		sort(G[i].begin(),G[i].end());
    for(int i=1;i<=m;i++)
    {
    	Data t;
    	scanf("%d%d%d",&u,&t.l,&t.r);
    	t.id=i;
    	b[u].pb(t);
    }
    getdis(1);
    build(1,1,n);
    dfs(1);
    for(int i=1;i<=m;i++)
    	printf("%I64d\n",ans[i]);
    return 0;
}