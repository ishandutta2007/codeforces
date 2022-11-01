#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)11*1000)
#define MOD ((ll)1e9+7)

struct Edge
{
	ll v,u,l,r;
	bool p;
};

ll n,m,k,s1,s2,f,dis[2][N];
vector <pair<ll,ll> > e[N];
Edge ed[N];

void dij(ll x,ll num)
{
	memset(dis[num],63,sizeof dis[num]);
	set <pair<ll,ll> > s;s.insert({0,x});dis[num][x]=0;
	while(s.size())
	{
		ll x=s.begin()->second;s.erase(s.begin());
		for(auto u:e[x])
		{
			if(u.first==-1)
			{
				ll v=ed[u.second].u;
				if(dis[num][v]>dis[num][x]+(ed[u.second].p?ed[u.second].r:ed[u.second].l))
					s.erase({dis[num][v],v}),dis[num][v]=dis[num][x]+(ed[u.second].p?ed[u.second].r:ed[u.second].l),s.insert({dis[num][v],v});
				continue;
			}
			if(dis[num][u.first]>dis[num][x]+u.second)
				s.erase({dis[num][u.first],u.first}),dis[num][u.first]=dis[num][x]+u.second,s.insert({dis[num][u.first],u.first});
		}
	}
}

void solve()
{
	dij(s1,0);dij(s2,1);
	while(1)
	{
		bool flg=0;
		for(int i=0;i<k;i++)
			if(ed[i].p && dis[0][ed[i].v]<dis[1][ed[i].v])
			{
				ed[i].p=0;flg=1;
				dij(s1,0);dij(s2,1);
			}
		if(!flg)break;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k>>s1>>s2>>f;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
	}
	for(int i=0;i<k;i++)
	{
		cin>>ed[i].v>>ed[i].u>>ed[i].l>>ed[i].r;ed[i].p=1;
		e[ed[i].v].push_back({-1,i});
	}
	solve();
	if(dis[0][f]>dis[1][f])return cout<<"LOSE",0;
	if(dis[0][f]==dis[1][f])cout<<"DRAW\n";
	else cout<<"WIN\n";
	for(int i=0;i<k;i++)cout<<(ed[i].p?ed[i].r:ed[i].l)<<" ";
	return 0;
}