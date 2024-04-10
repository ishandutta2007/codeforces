#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,n/=2,a*=a,a%=mod;return res;}
const ll N=((ll)101*1000);
const ll INF=((ll)2e18);
const ll MOD=((ll)109+7);

ll n,size[N];
vector <ll> e[N];
ld ans[N];

void dfs_pre(ll x)
{
	size[x]=1;
	for(int i=0;i<e[x].size();i++)
		dfs_pre(e[x][i]),size[x]+=size[e[x][i]];
}

void dfs(ll x)
{
	for(int i=0;i<e[x].size();i++)
	{
		ld ex=size[x]-1-size[e[x][i]];
			ex/=(ld)2;
		ans[e[x][i]]=ans[x]+1+ex;
	}
	for(int i=0;i<e[x].size();i++)
		dfs(e[x][i]);
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		e[x].push_back(i);
	}
	dfs_pre(1);
	ans[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++)
		cout<<fixed<<setprecision(12)<<ans[i]<<" ";
    return 0;
}