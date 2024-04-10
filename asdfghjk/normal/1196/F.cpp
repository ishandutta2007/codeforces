#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N=200005;
struct node
{
	int h;
	ll d;
}t;
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
struct edge
{
	int u,v,w;
}e[N];
int n,m,K,i,j,k,l,x,head[N],adj[N*2],nxt[N*2],len[N*2],pt[N],num;
bool v[N];
ll ans[640005],dis[N];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
void addedge(int u,int v,int w)
{
	adj[i*2-1]=v;
	nxt[i*2-1]=head[u];
	head[u]=i*2-1;
	adj[i*2]=u;
	nxt[i*2]=head[v];
	head[v]=i*2;
	len[i*2-1]=len[i*2]=w;
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&j,&k,&x);
		e[i].u=j,e[i].v=k,e[i].w=x;
	}
	sort(e+1,e+1+m,cmp);
	for(i=1;i<=m&&i<=K;++i)
		v[e[i].u]=v[e[i].v]=true;
	for(i=1,l=0;i<=n;++i)
		if(v[i])
			pt[i]=++l;
	for(i=1;i<=m&&i<=K;++i)
		addedge(pt[e[i].u],pt[e[i].v],e[i].w);
	for(i=1;i<=l;++i)
	{
		for(j=1;j<=l;++j)
			v[j]=false,dis[j]=1ll<<60;
		dis[i]=0;
		q.push((node){i,0});
		while(!q.empty())
		{
			t=q.top();
			q.pop();
			if(v[t.h])
				continue;
			v[t.h]=true;
			for(j=head[t.h];j;j=nxt[j])
				if(t.d+len[j]<dis[adj[j]])
				{
					dis[adj[j]]=t.d+len[j];
					q.push((node){adj[j],dis[adj[j]]});
				}
		}
		for(j=1;j<=l;++j)
			if(dis[j])
				ans[++num]=dis[j];
	}
	sort(ans+1,ans+1+num);
	printf("%lld",ans[2*K]);
	return 0;
}