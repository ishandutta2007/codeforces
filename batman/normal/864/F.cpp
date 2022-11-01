#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define ll int
#define N ((ll)3030)
#define Q ((ll)401*1000)

ll n,m,q,ans[Q],mark[N],dis[N];
vector <pair<ll,pair<ll,ll> > > qu[N];
vector <pair<ll,ll> > que[N];
vector <ll> e[N],now;

void dfs2(ll x)
{
	mark[x]=2;
	for(auto u:e[x])
	{
		if(mark[u]==1)
		{
			while(now.size() && dis[now.back()]>=dis[u])
			{
				ll v=now.back();now.pop_back();
				for(auto v2:e[v])
					if(mark[v2]==0)
						dfs2(v2);
			}
		}
		if(mark[u]==0)
			dfs2(u);
	}
}

void dfs(ll x)
{
	mark[x]=1;
	now.push_back(x);
	for(auto u:que[x])
		if(u.first<=now.size())
			ans[u.second]=now[u.first-1];
	for(auto u:e[x])
	{
		if(mark[u]==2)continue;
		if(mark[u]==0)
		{
			dis[u]=dis[x]+1;dfs(u);
			continue;
		}
		while(now.size() && dis[now.back()]>=dis[u])
		{
			ll v=now.back();now.pop_back();
			for(auto v2:e[v])
				if(mark[v2]==0)
					dfs2(v2);
		}
	}
	mark[x]=2;
	if(now.back()==x)now.pop_back();
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)sort(e[i].begin(),e[i].end());
	for(int i=0;i<q;i++)
	{
		ll v,u,k;
		scanf("%d%d%d",&v,&u,&k);
		qu[v].push_back({u,{k,i}});
	}
	for(int i=1;i<=n;i++)
	{
		memset(mark,0,sizeof mark);now.clear();
		for(int j=1;j<=n;j++)que[j].clear();
		for(auto u:qu[i])
			que[u.first].push_back(u.second);
		dis[i]=0;dfs(i);
	}
	for(int i=0;i<q;i++)printf("%d\n",ans[i]?ans[i]:-1);
	return 0;
}