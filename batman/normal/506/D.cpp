#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define SQ ((ll)300)

ll n,m,q,sz,ans[N];
vector <pair<ll,ll> > ed[N],qu;
vector <ll> v,e[N];
vector <vector<ll> > piles;
ll mark[N];

set <pair<ll,ll> > id;
map <pair<ll,ll>,ll> anss;

void dfs(ll x)
{
	piles[sz].push_back(x);
	mark[x]=2;
	for(auto u:e[x])
		if(mark[u]==1)
			dfs(u);
}

bool cmp(vector <ll> &x,vector <ll> &y){return x.size()>y.size();}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed[w].push_back({v,u});
	}
	for(int i=1;i<=m;i++)
		if(ed[i].size())
		{
			for(auto x:ed[i])
			{
				v.push_back(x.first);v.push_back(x.second);
				mark[x.first]=mark[x.second]=1;
				e[x.first].push_back(x.second);
				e[x.second].push_back(x.first);
			}
			for(auto x:v)
				if(mark[x]==1)
				{
					vector <ll> ex;
					piles.push_back(ex);
					dfs(x),sz++;
				}
			for(auto x:v)
				mark[x]=0,e[x].clear();
			v.clear();
		}
	
	cin>>q;
	for(int i=0;i<q;i++)
	{
		ll v,u;
		cin>>v>>u;
		qu.push_back({v,u});
		id.insert({v,u});
	}
	sort(piles.begin(),piles.end(),cmp);
	for(int i=0;i<SQ && i<piles.size();i++)
	{
		unordered_map <ll,bool> mp;
		for(auto x:piles[i])
			mp[x]=1;
		for(int j=0;j<q;j++)
			if(mp[qu[j].first] && mp[qu[j].second])
				ans[j]++;
	}
	for(int i=SQ;i<piles.size();i++)
		for(int j=0;j<piles[i].size();j++)
			for(int k=0;k<piles[i].size();k++)
				if(id.count({piles[i][j],piles[i][k]})==1)
					anss[{piles[i][j],piles[i][k]}]++;
	for(int i=0;i<q;i++)cout<<ans[i]+anss[{qu[i].first,qu[i].second}]<<"\n";
	return 0;
}