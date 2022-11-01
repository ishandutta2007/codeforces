#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (301*1000)
#define INF ((ll)1e16)

ll n,m,t,d[N],ans;
vector <pair<ll,pair<ll,ll> > > e[N];
pair <ll,ll> par[N];

int main()
{
    scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		scanf("%d%d%d",&v,&u,&w);
		e[v].push_back({u,{w,i+1}});
		e[u].push_back({v,{w,i+1}});
	}
	scanf("%d",&t);
	for(int i=0;i<N;i++)d[i]=INF,par[i]={INF,INF};
	d[t]=par[t].first=par[t].second=0;
	set <pair<ll,ll> > s;s.insert({0,t});
	while(s.size())
	{
		ll x=s.begin()->second;s.erase(s.begin());
		for(int i=0;i<e[x].size();i++)
		{
			if(d[x]+e[x][i].second.first<d[e[x][i].first])
				s.erase({d[e[x][i].first],e[x][i].first}),d[e[x][i].first]=d[x]+e[x][i].second.first,s.insert({d[e[x][i].first],e[x][i].first});
			if(d[x]+e[x][i].second.first==d[e[x][i].first] && par[e[x][i].first].first>e[x][i].second.first)
				ans+=e[x][i].second.first-((par[e[x][i].first].first!=INF)?par[e[x][i].first].first:0ll),par[e[x][i].first]={e[x][i].second.first,e[x][i].second.second};	
		}
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;i++)
		if(i!=t)
			printf("%d ",par[i].second);
    return 0;
}