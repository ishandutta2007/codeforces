#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define MOD ((ll)1e9+7)

ll n,dp_down[N],dp_up[N];
vector <pair <ll,bool> > e[N];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i].first])
		{
			dfs(e[x][i].first);
			dp_down[x]+=dp_down[e[x][i].first]+(e[x][i].second);
		}
	mark[x]=0;
}

void dfs2(ll x)
{
	mark[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i].first])
		{
			dp_up[e[x][i].first]=dp_up[x]+dp_down[x]-(dp_down[e[x][i].first]+(e[x][i].second))+!e[x][i].second;
			dfs2(e[x][i].first);
		}
	mark[x]=0;		
}

int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
    	ll v,u;
    	cin>>v>>u;
    	e[v].push_back({u,0});
    	e[u].push_back({v,1});
	}
	dfs(1);
	dp_down[0]=dp_down[1];
	dfs2(1);
	ll mini=1e9;
	for(int i=1;i<=n;i++)mini=min(mini,dp_down[i]+dp_up[i]);
	cout<<mini<<"\n";
    for(int i=1;i<=n;i++)if(dp_down[i]+dp_up[i]==mini)cout<<i<<" ";
	return 0;
}