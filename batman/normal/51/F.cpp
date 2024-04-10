#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)2100)

ll n,m,mark[N],ans;
vector <ll> e1[N],e2[N];
vector <pair<ll,ll> > ed;
stack <ll> tpl;

ll cnt,num[N],comp;
vector <ll> e[N];

void dfs1(ll x,ll par=0)
{
	mark[x]=1;
	for(auto u:e1[x])
	{
		if(u==par || mark[u]==2)continue;
		e2[u].push_back(x);
		if(!mark[u])dfs1(u,x);
	}
	mark[x]=2;
	tpl.push(x);
}

void dfs2(ll x)
{
	mark[x]=1;num[x]=cnt;
	for(auto u:e2[x])
		if(!mark[u])
			dfs2(u);
}

ll maxi,maxi_id,now,num_;

void dfs(ll x,ll par=0)
{
	mark[x]=1;
	if(e[x].size()>1)num_++;
	if(now>maxi)maxi=now,maxi_id=x;
	for(auto u:e[x])
		if(u!=par)
			now++,dfs(u,x),now--;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e1[v].push_back(u);
		e1[u].push_back(v);
		ed.push_back({v,u});
	}
	for(int i=1;i<=n;i++)if(!mark[i])dfs1(i);
	memset(mark,0,sizeof mark);
	while(tpl.size())
	{
		ll x=tpl.top();tpl.pop();
		if(mark[x])continue;
		cnt++;
		dfs2(x);
	}
	ans=n-cnt;
	for(auto u:ed)
	{
		ll x=num[u.first],y=num[u.second];
		if(x!=y)e[x].push_back(y),e[y].push_back(x);
	}
	memset(mark,0,sizeof mark);
	for(int i=1;i<=cnt;i++)
		if(!mark[i])
		{
			comp++;
			maxi=-1;dfs(i);
			maxi=-1;num_=0;dfs(maxi_id);
			ans+=num_-maxi+1-((ll)e[i].size()==0);
		}
	ans+=comp-1;
	cout<<ans;
	return 0;
}