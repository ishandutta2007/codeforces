#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)
#define K (60)
#define INF ((ll)1e9)

ll n,par[N],ans,m,dp[N][K],maxi[N][K],dis[N],res[N];
bool mark[N];
vector <pair<ll,ll> > e[N];
vector <pair <pair<ll,ll> ,pair<ll,ll> > > ed;

ll root(int x){if(par[x]<0)return x;par[x]=root(par[x]);return par[x];}
void merge(ll x,ll y){x=root(x);if(y>0)y=root(y);par[x]=y;}

void dfs(ll x)
{
	mark[x]=1;
	for(int i=1;i<K;i++)
		dp[x][i]=dp[dp[x][i-1]][i-1],maxi[x][i]=max(maxi[x][i-1],maxi[dp[x][i-1]][i-1]);
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i].first])
			dis[e[x][i].first]=dis[x]+1,dp[e[x][i].first][0]=x,maxi[e[x][i].first][0]=e[x][i].second,dfs(e[x][i].first);
	mark[x]=0;				
}

ll iPar(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=dp[x][i];
	return x;
}

ll iMax(ll x,ll num)
{
	ll imax=0;
	for(int i=0;num;i++,num/=2)
		if(num%2)imax=max(imax,maxi[x][i]),x=dp[x][i];
	return imax;
}

ll lca(ll x,ll y,ll k)
{
	ll i=k-1;
	for(;i>=0;i--)
		if(dp[x][i]!=dp[y][i])
			break;
	if(i<0)return dp[x][0];
	return lca(dp[x][i],dp[y][i],i);
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
	for(int i=0;i<ed.size();i++)
	{
	    ll u=ed[i].second.first;
    	ll v=ed[i].second.second;
	    ll w=ed[i].first.first;
    	if(root(u)!=root(v))
		{	
			ans+=w;
			e[v].push_back({u,w});
			e[u].push_back({v,w});
			merge(u,v);
		}
	}
	dfs(1);
	for(int i=0;i<ed.size();i++)
	{
		ll u=ed[i].second.first;
    	ll v=ed[i].second.second;
    	ll w=ed[i].first.first;
    	ll id=ed[i].first.second;
    	bool p=0;
    	for(int i=0;i<e[u].size();i++)
    		if(e[u][i].first==v)
    		{
    			p=1,res[id]=ans;
    			break;
			}
		if(p)continue;
		
		if(dis[u]<dis[v])swap(u,v);
		if(iPar(u,dis[u]-dis[v])==v)
		{
			res[id]=ans+w-iMax(u,dis[u]-dis[v]);
			continue;	
		}
		ll imax=iMax(u,dis[u]-dis[v]);
		u=iPar(u,dis[u]-dis[v]);
		ll cPar=lca(u,v,K);
		imax=max(imax,max(iMax(u,dis[u]-dis[cPar]),iMax(v,dis[v]-dis[cPar])));
		res[id]=ans+w-imax;
	}
	for(int i=0;i<m;i++)
		cout<<res[i]<<"\n";
		
    return 0;
}