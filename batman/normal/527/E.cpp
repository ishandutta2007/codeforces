#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)501*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)

ll n,m,mark[N],it[N],cnt;
pair <ll,ll> ans[N];
vector <pair<ll,ll> > e[N];


void dfs(ll x)
{
	while(it[x]!=e[x].size())
	{
		pair <ll,ll> u=e[x][it[x]];it[x]++;
		if(mark[u.second])continue;
		mark[u.second]=1;
		dfs(u.first);
		cnt++;
		if(cnt%2)ans[u.second]={x,u.first};
		else ans[u.second]={u.first,x};
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	ll v,u;
    	cin>>v>>u;
    	e[v].push_back({u,i});
    	e[u].push_back({v,i});
	}
	for(int i=1,lst=-1;i<=n;i++)
		if((ll)e[i].size()%2)
		{
			if(lst==-1)lst=i;
			else e[i].push_back({lst,m}),e[lst].push_back({i,m}),lst=-1,m++;
		}
	dfs(1);
	if(m%2)ans[m++]={1,1};
	cout<<m<<"\n";
	for(int i=0;i<m;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}