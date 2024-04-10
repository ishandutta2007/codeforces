#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define K (60)
#define INF ((ll)1e15)

ll n,m,ans[N],d[N],sub_d[N];
vector <pair<pair<ll,ll>,pair<ll,ll> > > ed;
vector <pair<ll,pair<ll,bool> > > e[N];
bool mark[N];
ll par[N];

ll root(int x){if(par[x]<0)return x;par[x]=root(par[x]);return par[x];}
void merge(ll x,ll y){x=root(x);if(y>0)y=root(y);par[x]=y;}

void dfs(ll x,ll id_par=-1)
{
	bool cut=0;
	mark[x]=1;
	sub_d[x]=d[x];
	for(int i=0;i<e[x].size();i++)
		if(e[x][i].second.second)
		{
			if(!mark[e[x][i].first])
				d[e[x][i].first]=d[x]+1,dfs(e[x][i].first,e[x][i].second.first);
			if(e[x][i].second.first!=id_par)
			{
				sub_d[x]=min(sub_d[x],sub_d[e[x][i].first]);
				if(sub_d[e[x][i].first]>d[x])
					ans[e[x][i].second.first]=1;
			}
			e[x][i].second.second=0;
		}
}

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=-i;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed.push_back({{w,i},{u,v}});
	}
	sort(ed.begin(),ed.end());
	ll i=0;
	while(i<ed.size())
	{
		map <pair<ll,ll>,vector <ll> > mp;
		ll j=i,p=0;
		while(ed[j].first.first==ed[i].first.first)
		{
			ll v=root(ed[j].second.first),u=root(ed[j].second.second);
			p=v;
			if(u==v)ans[ed[j].first.second]=2;
			e[u].push_back({v,{ed[j].first.second,1}});
			e[v].push_back({u,{ed[j].first.second,1}});
			j++;
		}
		dfs(p);
		j=i;
		while(ed[j].first.first==ed[i].first.first)
		{
			ll v=root(ed[j].second.first),u=root(ed[j].second.second);
			if(u!=v)merge(u,v);
			d[u]=d[v]=sub_d[u]=sub_d[v]=mark[v]=mark[u]=0;
			j++;
		}
		i=j;
		
	}
	for(int i=0;i<m;i++)
	{
		if(ans[i]==1)cout<<"any\n";
		else if(ans[i]==0)cout<<"at least one\n";
		else cout<<"none\n";	
	}   
	
    return 0;
}