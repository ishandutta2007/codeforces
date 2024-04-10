#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,s,edge_t=0,t,ans=0,e_t=0;
bool ok;
int la[200002],lae[200002],deg[200002],rt[200002],siz[200002];
LL dis[200002];
bool vis[200002];
vector<int> vec[200002];
typedef pair<LL,int> P;P p;
priority_queue<P,vector<P>,greater<P> > pq;
queue<int> q;
struct aaa
{
	int to,nx,val;
}edge[600002];
struct bbb
{
	int to,nx;
}e[600002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(bbb){y,lae[x]},lae[x]=e_t,++deg[y];
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs1(int x)
{
	if(x!=s)ans=max(ans,siz[x]);
	vis[x]=1;
	for(int i=lae[x],v;i;i=e[i].nx)if(!vis[v=e[i].to])dfs1(v);
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	for(int i=1;i<=n;++i)dis[i]=inf,rt[i]=i,siz[i]=1;
	for(pq.push(P(dis[s]=0,s));!pq.empty();)
	{
		p=pq.top(),pq.pop();
		if(dis[p.second]<p.first)continue;
		for(int i=la[p.second],v;i;i=edge[i].nx)if(dis[v=edge[i].to]>p.first+edge[i].val)pq.push(P(dis[v]=p.first+edge[i].val,v));
	}
	for(int i=1;i<=m;++i)
	{
		if(dis[edge[(i<<1)-1].to]+edge[i<<1].val==dis[edge[i<<1].to])add_e(edge[(i<<1)-1].to,edge[i<<1].to);
		if(dis[edge[i<<1].to]+edge[i<<1].val==dis[edge[(i<<1)-1].to])add_e(edge[i<<1].to,edge[(i<<1)-1].to);
	}
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
	for(;!q.empty();)
	{
		t=q.front(),q.pop(),ok=(!vec[t].empty());
		for(int i=0;i<vec[t].size();++i)
		{
			getroot(vec[t][i]);
			if(rt[vec[t][i]]!=rt[vec[t][0]])
			{
				ok=0;
				break;
			}
		}
		if(ok && rt[vec[t][0]]!=s && t!=s)++siz[rt[vec[t][0]]],getroot(t),rt[rt[t]]=rt[vec[t][0]];
		for(int i=lae[t],v;i;i=e[i].nx)
		{
			if(!(--deg[v=e[i].to]))q.push(v);
			vec[v].push_back(t);
		}
	}
	dfs1(s);
	return 0&printf("%d",ans);
}