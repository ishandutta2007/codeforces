#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll int
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=2510;
const ll K=20;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,a[N][N],dsu_par[N],dis[N],dp_max[N][K],dp_par[N][K];
vector <pair<ll,pair<ll,ll> > > ed;
vector <pair<ll,ll> > e[N];

ll root(ll x){if(dsu_par[x]==-1)return x;return dsu_par[x]=root(dsu_par[x]);}

void dfs(ll x,ll par=0,ll par_e=0)
{
	dp_max[x][0]=par_e,dp_par[x][0]=par;
	for(int i=1;i<K;i++)
		dp_par[x][i]=dp_par[dp_par[x][i-1]][i-1],dp_max[x][i]=max(dp_max[x][i-1],dp_max[dp_par[x][i-1]][i-1]);
	for(int i=0;i<e[x].size();i++)
		if(e[x][i].first!=par)
			dis[e[x][i].first]=dis[x]+1,dfs(e[x][i].first,x,e[x][i].second);
}

ll IPar(ll x,ll num)
{
	for(int i=0;i<K;i++,num/=2)
		if(num%2)
			x=dp_par[x][i];
	return x;
}

ll IMax(ll x,ll num)
{
	ll res=0;
	for(int i=0;i<K;i++,num/=2)
		if(num%2)
			res=max(res,dp_max[x][i]),x=dp_par[x][i];
	return res;
}

ll lca(ll x,ll y)
{
	if(dis[x]>dis[y])swap(x,y);
	y=IPar(y,dis[y]-dis[x]);
	if(y==x)return x;
	for(int i=K-1;i>=0;i--)
		if(dp_par[x][i]!=dp_par[y][i])
			x=dp_par[x][i],y=dp_par[y][i];
	return dp_par[x][0];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<N;i++)dsu_par[i]=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(i==j && a[i][j]!=0)return cout<<"NOT MAGIC",0;
			if(i>j && a[i][j]!=a[j][i])return cout<<"NOT MAGIC",0;
			if(i<j)ed.push_back({a[i][j],{i,j}});
		}
	sort(ed.begin(),ed.end());
	for(int i=0;i<ed.size();i++)
		if(root(ed[i].second.first)!=root(ed[i].second.second))
		{
			dsu_par[root(ed[i].second.first)]=root(ed[i].second.second);
			e[ed[i].second.first].push_back({ed[i].second.second,ed[i].first});
			e[ed[i].second.second].push_back({ed[i].second.first,ed[i].first});
		}
	dfs(1);
	for(int i=0;i<ed.size();i++)
	{
		ll x=ed[i].second.first,y=ed[i].second.second;
		ll p=lca(x,y);
		//cout<<IMax(x,dis[x]-dis[p])<<" "<<IMax(y,dis[y]-dis[p])<<"\n";
		if(max(IMax(x,dis[x]-dis[p]),IMax(y,dis[y]-dis[p]))!=ed[i].first)return cout<<"NOT MAGIC",0;
	}
	cout<<"MAGIC";
	return 0;
}