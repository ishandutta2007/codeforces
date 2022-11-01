#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N (101*1000)

ll n,m,d[N],par[N],num[N];
vector <pair <ll,bool> > e[N];
map <pair<ll,ll>,ll> mp;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		bool p;
		cin>>v>>u>>p;
		e[u].push_back({v,p});
		e[v].push_back({u,p});
		mp[{v,u}]=mp[{u,v}]=p;
	}
	
	queue <ll> q;
	d[1]=1;
	q.push(1);
	while(q.size())
	{
		ll x=q.front();
		q.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(!d[e[x][i].first])
				d[e[x][i].first]=d[x]+1,par[e[x][i].first]=x,num[e[x][i].first]=num[x]+e[x][i].second,q.push(e[x][i].first);
			else if(d[x]<d[e[x][i].first] && num[x]+e[x][i].second>num[e[x][i].first])
				par[e[x][i].first]=x,num[e[x][i].first]=num[x]+e[x][i].second;	
		}
	}
	vector <pair<pair<ll,ll>,bool> > ans;
	for(int i=n;i>1;i=par[i])
	{
		if(mp[{i,par[i]}]==0)
			ans.push_back({{i,par[i]},1});
		mp[{i,par[i]}]=mp[{par[i],i}]=2;	
	}
		
	for(map <pair<ll,ll>,ll>::iterator it=mp.begin();it!=mp.end();it++)
		if(it->second==1)
			ans.push_back({{it->first.first,it->first.second},0}),mp[{it->first.second,it->first.first}]=2;	
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<"\n";
	return 0;
}