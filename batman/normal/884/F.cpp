#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)10*1000)
#define K ((ll)26)
#define INF ((ll)1e9)

ll n,b[N],cnt[K],sum;
string s;
ll from[N],to[N],cap[N],cost[N],prv[N],head[N],cnt_ed;
ll dis[N],par[N];
bool mark[N];

void add_edge(ll x,ll y,ll w,ll c)
{
	from[cnt_ed]=x;to[cnt_ed]=y;cap[cnt_ed]=w;cost[cnt_ed]=c;prv[cnt_ed]=head[x];head[x]=cnt_ed;cnt_ed++;
	from[cnt_ed]=y;to[cnt_ed]=x;cap[cnt_ed]=0;cost[cnt_ed]=-c;prv[cnt_ed]=head[y];head[y]=cnt_ed;cnt_ed++;
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
					mark[to[u]]=1,q.push(to[u]);
			}
	}
	return (dis[snk]<INF);
}

pair <ll,ll> max_flow(ll src,ll snk)
{
	pair <ll,ll> res;res={0,0};
	while(shortest_path(src,snk))
	{
		res.first++;
		ll x=snk;
		while(x!=src)
		{
			res.second+=cost[par[x]];
			cap[par[x]]--;
			cap[par[x]^1]++;
			x=from[par[x]];
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	memset(head,-1,sizeof head);
	for(int i=0;i<n;i++)cin>>b[i],sum+=b[i],cnt[s[i]-'a']++;
	for(int i=0;i<K;i++)
	{
		add_edge(0,i+1,cnt[i],0);
		for(int j=0;j<n/2;j++)
		{
			add_edge(i+1,27+i*(n/2)+j,1,0);
			add_edge(27+i*(n/2)+j,27+K*(n/2)+j,1,b[j]*(i!=(s[j]-'a')));
			add_edge(27+i*(n/2)+j,27+K*(n/2)+n-j-1,1,b[n-j-1]*(i!=(s[n-j-1]-'a')));	
		}
	}
	for(int i=0;i<n;i++)add_edge(27+K*(n/2)+i,N-1,1,0);
	cout<<sum-max_flow(0,N-1).second<<"\n";
	return 0;
}