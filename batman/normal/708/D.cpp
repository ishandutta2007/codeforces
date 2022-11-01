#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define INF ((ll)1e9)

ll n,m,val[N],dis[N],par[N],res;
ll from[N],to[N],cap[N],cost[N],head[N],prv[N],ec;
bool mark[N];

void add_edge(ll x,ll y,ll w,ll c)
{
	from[ec]=x;to[ec]=y;cap[ec]=w;cost[ec]=c;prv[ec]=head[x];head[x]=ec;ec++;
	from[ec]=y;to[ec]=x;cap[ec]=0;cost[ec]=-c;prv[ec]=head[y];head[y]=ec;ec++;
}

bool shortest_path(ll src,ll snk)
{
	for(int i=0;i<N;i++)dis[i]=INF;
	queue <ll> q;
	dis[src]=0;q.push(src);mark[src]=1;
	while(q.size())
	{
		ll x=q.front();q.pop();mark[x]=0;
		for(ll u=head[x];u!=-1;u=prv[u])
			if(cap[u]>0 && dis[to[u]]>dis[x]+cost[u])
			{
				dis[to[u]]=dis[x]+cost[u];
				par[to[u]]=u;
				if(!mark[to[u]])
					q.push(to[u]),mark[to[u]]=1;
			}
	}
	return dis[snk]<INF;
}

pair <ll,ll> max_flow(ll src,ll snk)
{
	pair <ll,ll> res;res={0,0};
	while(shortest_path(src,snk))
	{
		vector <ll> ex;
		ll x=snk,mini=INF;
		while(x!=src)
		{
			mini=min(mini,cap[par[x]]);
			ex.push_back(par[x]);
			x=from[par[x]];
		}
		res.first+=mini;
		for(auto u:ex)
			res.second+=mini*cost[u],
			cap[u]-=mini,
			cap[u^1]+=mini;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof head);
	for(int i=0;i<m;i++)
	{
		ll v,u,c,f;
		cin>>v>>u>>c>>f;
		if(u==n)u=1;
		val[v]+=f;val[u]-=f;
		if(c>f)
			add_edge(u,v,f,1),
			add_edge(v,u,c-f,1),
			add_edge(v,u,INF,2);
		else
			res+=f-c,
			add_edge(u,v,f-c,0),
			add_edge(u,v,c,1),
			add_edge(v,u,INF,2);
			
	}
	for(int i=1;i<n;i++)
	{
	//	cout<<val[i]<<"\n";
		if(val[i]<0)add_edge(0,i,-val[i],0);
		else add_edge(i,n,val[i],0);
	}
	cout<<res+max_flow(0,n).second<<"\n";
	return 0;
}