#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)

ll n,dp_up[N],dp_down[N],sz[N],now_sz,dis[N],a[N],ans[N];
vector <pair<ll,ll> > e[N];
vector <ll> cycle;
bool mark[N],dead[N];

bool dfs_cycle(ll x,ll par=0)
{
	cycle.push_back(x);
	mark[x]=1;
	for(auto u:e[x])
	{
		if(u.first==par)continue;
		if(mark[u.first])
		{
			vector <ll> ex;
			while(1)
			{
				ex.push_back(cycle.back());
				dead[cycle.back()]=1;
				if(cycle.back()==u.first)break;
				cycle.pop_back();
			}
			cycle=ex;
			return 1;
		}
		if(dfs_cycle(u.first,x))return 1;
	}
	cycle.pop_back();
	return 0;
}

void dfs_down(ll x,ll par=0)
{
	sz[x]=1;
	for(auto u:e[x])
	{
		if(u.first==par || dead[u.first])continue;
		dfs_down(u.first,x);
		sz[x]+=sz[u.first];
		dp_down[x]+=dp_down[u.first]+u.second*sz[u.first];
	}
}

void dfs_up(ll x,ll par=0)
{
	for(auto u:e[x])
	{
		if(u.first==par || dead[u.first])continue;
		dp_up[u.first]=(now_sz-sz[u.first])*u.second+dp_up[x]+dp_down[x]-(dp_down[u.first]+sz[u.first]*u.second);
		dfs_up(u.first,x);
	}
}

void dfs_final(ll x,ll root,ll dis_root=0,ll par=0)
{
	ans[x]=dp_down[x]+dp_up[x]+a[root]+dis_root*(n-sz[root]);
	for(auto u:e[x])
	{
		if(u.first==par || dead[u.first])continue;
		dfs_final(u.first,root,dis_root+u.second,x);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	dfs_cycle(1);
	for(auto u:cycle)dfs_down(u),now_sz=sz[u],dfs_up(u);
	ll sum=0,now=0,frnt=0,bck=0,t_frnt=0,t_bck=0;
	for(int i=0;i<cycle.size();i++)
	{
		ll now=cycle[i],nxt=cycle[(i+1)%((ll)cycle.size())];
		for(auto u:e[now])
			if(u.first==nxt)
			{
				dis[i]=u.second;
				sum+=dis[i];
				break;
			}
	}
	for(int i=(ll)cycle.size()-1,gigil=0;i>0;i--)
	{
		gigil+=dis[i];
		bck+=gigil*sz[cycle[i]]+dp_down[cycle[i]];
		t_bck+=sz[cycle[i]];
	}
	for(int i=0,j=0;i<cycle.size();i++)
	{
		while(now+dis[j]<=sum/2)
		{
			ll nxt=cycle[(j+1)%((ll)cycle.size())];
			now+=dis[j];
			frnt+=now*sz[nxt]+dp_down[nxt];
			bck-=(sum-now)*sz[nxt]+dp_down[nxt];
			j=(j+1)%((ll)cycle.size());
			t_frnt+=sz[cycle[j]];
			t_bck-=sz[cycle[j]];
		}
		a[cycle[i]]=frnt+bck;
		dfs_final(cycle[i],cycle[i]);
		if(i==(ll)cycle.size()-1)break;
		bck+=dp_down[cycle[i]];
		t_bck+=sz[cycle[i]];
		bck+=dis[i]*t_bck;
		if(!frnt){t_bck-=sz[cycle[i+1]];bck-=sum*sz[cycle[i+1]]+dp_down[cycle[i+1]];j++;continue;}
		now-=dis[i];
		frnt-=dp_down[cycle[i+1]]+dis[i]*t_frnt;
		t_frnt-=sz[cycle[i+1]];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}