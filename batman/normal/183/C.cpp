#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (101*1000)

ll n,m,ans,mark[N];
vector <pair <ll,bool> > e[N];

void dfs(ll x)
{
	for(int i=0;i<e[x].size();i++)
	{
		if(!mark[e[x][i].first])
			mark[e[x][i].first]=mark[x]+((e[x][i].second)?1:-1),dfs(e[x][i].first);
		else
		{
			if(ans==0)
				ans=abs(mark[x]+((e[x][i].second)?1:-1)-mark[e[x][i].first]);
			else
				ans=__gcd(ans,abs(mark[x]+((e[x][i].second)?1:-1)-mark[e[x][i].first]));
		}
		mark[e[x][i].first]=mark[x]+((e[x][i].second)?1:-1);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back({u,1});
		e[u].push_back({v,0});
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			mark[i]=(ll)1e6,dfs(i);
	if(ans==0)
		cout<<n;
	else
		cout<<ans;
    return 0;
}