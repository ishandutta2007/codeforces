#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,a[N];
vector <ll> e[N],ans;
bool child[N];

void dfs(ll x,ll par=0)
{
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
		{
			ll v=e[x][i];
			dfs(v,x);
			if(a[v]!=v && a[v]!=a[x])
			{
				cout<<-1;
				exit(0);
			}
		}
	if(a[x]==x)ans.push_back(x);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		child[u]=1;
		e[v].push_back(u);
		e[u].push_back(v);	
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(!child[i])
			dfs(i);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<"\n";
	return 0;
}