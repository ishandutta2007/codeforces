#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)22)
#define MOD ((ll)1e9+7)

ll n,q,dp_down[2][N],dp_up[2][N],dis[N],dis_w[N],par[K][N],sz[N];
vector <pair<ll,ll> > e[N];

void dfs_down(ll x)
{
	sz[x]=1;
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u.first!=par[0][x])
		{
			par[0][u.first]=x;
			dis[u.first]=dis[x]+1;
			dis_w[u.first]=dis_w[x]+u.second;dis_w[u.first]%=MOD;
			dfs_down(u.first);
			sz[x]+=sz[u.first];
			dp_down[0][x]+=dp_down[0][u.first]+sz[u.first]*u.second;dp_down[0][x]%=MOD;
			ll ex=u.second*u.second;ex%=MOD;ex*=sz[u.first];ex%=MOD;
			dp_down[1][x]+=dp_down[1][u.first]+ex+2*u.second*dp_down[0][u.first];dp_down[1][x]%=MOD;
		}
}

void dfs_up(ll x)
{
	for(auto u:e[x])
		if(u.first!=par[0][x])
		{
			ll num=dp_up[0][x]+dp_down[0][x]-(dp_down[0][u.first]+sz[u.first]*u.second);num%=MOD;num+=MOD;num%=MOD;
			dp_up[0][u.first]=num+(n-sz[u.first])*u.second;dp_up[0][u.first]%=MOD;
			ll ex=u.second*u.second;ex%=MOD;ex*=sz[u.first];ex%=MOD;
			ll num2=dp_up[1][x]+dp_down[1][x]-(ex+dp_down[1][u.first]+2*u.second*dp_down[0][u.first]);num2%=MOD;num2+=MOD;num2%=MOD;
			ex=u.second*u.second;ex%=MOD;ex*=(n-sz[u.first]);ex%=MOD;
			dp_up[1][u.first]=num2+ex+2*u.second*num;dp_up[1][u.first]%=MOD;
			dfs_up(u.first);
		}
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	dfs_down(1);
	dfs_up(1);
	cin>>q;
	while(q--)
	{
		ll u,v;
		cin>>u>>v;
		ll p=lca(u,v);
		if(p!=v)
		{
			ll diss=dis_w[u]+dis_w[v]-2*dis_w[p];diss%=MOD;diss+=MOD;diss%=MOD;
			ll ex=diss*diss;ex%=MOD;ex*=sz[v];ex%=MOD;
			ll num=dp_down[1][v]+ex+2*diss*dp_down[0][v];num%=MOD;
			ll ans=2*num-(dp_down[1][u]+dp_up[1][u]);ans%=MOD;ans+=MOD;ans%=MOD;
			cout<<ans<<"\n";
		}
		else
		{
			ll diss=dis_w[u]-dis_w[v];diss%=MOD;diss+=MOD;diss%=MOD;
			ll ex=diss*diss;ex%=MOD;ex*=(n-sz[v]);ex%=MOD;
			ll num=dp_up[1][v]+ex+2*diss*dp_up[0][v];num%=MOD;
			ll ans=dp_down[1][u]+dp_up[1][u]-2*num;ans%=MOD;ans+=MOD;ans%=MOD;
			cout<<ans<<"\n";
		}
	}
	return 0;
}