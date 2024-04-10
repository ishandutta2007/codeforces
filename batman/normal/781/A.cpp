#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)

ll n,c[N],ans;
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	ans=max(ans,c[x]);
	ll num=1;
	for(auto u:e[x])
	{
		if(u==par)continue;
		while(num==c[x] || num==c[par])num++;
		c[u]=num++;
		dfs(u,x);
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
    	ll v,u;
    	cin>>v>>u;
    	e[v].push_back(u);
    	e[u].push_back(v);
	}
	c[1]=1;dfs(1);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
    return 0;
}