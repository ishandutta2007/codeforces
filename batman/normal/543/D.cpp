#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)
#define MOD ((ll)1e9+7)

ll n,par[N],dp_up[N],dp_down[N];
vector <ll> child[N];
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

void dfs(ll x)
{
	dp_down[x]=1;
	for(int i=0;i<child[x].size();i++)
	{
		dfs(child[x][i]);
		dp_down[x]*=dp_down[child[x][i]]+1;
		dp_down[x]%=MOD;
	}
}

void dfs2(ll x)
{
	if((dp_down[x]+1)%MOD)
		dp_up[x]=(dp_up[par[x]]*((dp_down[par[x]]*tavan((dp_down[x]+1)%MOD,MOD-2,MOD))%MOD)+1)%MOD;
	else
	{
		ll ex=1;
		for(int i=0;i<child[par[x]].size();i++)
			if(child[par[x]][i]!=x)
				ex*=dp_down[child[par[x]][i]]+1,ex%=MOD;
		dp_up[x]=(dp_up[par[x]]*(ex%MOD)+1)%MOD;		
	}	
	for(int i=0;i<child[x].size();i++)
		dfs2(child[x][i]);
}

int main()
{
    cin>>n;
    for(int i=2;i<=n;i++)
    {
    	cin>>par[i];
    	child[par[i]].push_back(i);
	}
	dfs(1);
	dfs2(1);
	//cout<<dp_up[1]<<"\n";
	for(int i=1;i<=n;i++)
	{
		cout<<(dp_up[i]*dp_down[i])%MOD<<" ";
	}
    return 0;
}