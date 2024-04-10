#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)220)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll t,n,m,it[N];
vector <ll> e[N];
set <pair<ll,ll> > s;
bool mark[N];

void dfs(ll x)
{
	while(it[x]<(ll)e[x].size())
	{
		ll v=e[x][it[x]];
		it[x]++;
		if(s.count({v,x})==1)continue;
		s.insert({x,v});
		dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<=n;i++)e[i].clear(),it[i]=0;
		memset(mark,0,sizeof mark);
		s.clear();
		for(int i=0;i<m;i++)
		{
			ll v,u;
			cin>>v>>u;
			e[v].push_back(u);
			e[u].push_back(v);
		}
		ll ans=n;
		for(int i=1;i<=n;i++)
			if(((ll)e[i].size())%2==1)
			{
				ans--;
				e[0].push_back(i);
				e[i].push_back(0);
			}
		for(int i=1;i<=n;i++)
			if(it[i]==0)
				dfs(i);
		cout<<ans<<"\n";
		for(auto x:s)if(x.first && x.second)cout<<x.first<<" "<<x.second<<"\n";
	}
	return 0;
}