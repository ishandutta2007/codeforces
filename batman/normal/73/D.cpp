#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)

ll n,m,k,num,ed,t;
vector <ll> e[N];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;num++;
	for(auto u:e[x])
		if(!mark[u])
			dfs(u);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)if(!mark[i])num=0,dfs(i),ed+=min(num,k),t++;
	ed/=2;
	if(k==1)return cout<<max(0ll,t-2),0;
	cout<<max(0ll,t-1-ed);
	return 0;
}