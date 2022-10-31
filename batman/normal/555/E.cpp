#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=201*1000;
const ll K=20;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,q;
bool mark[N];

vector <pair<ll,ll> > e[N],ed;
ll dir[N];

vector <ll> e2[N],e_rev[N];
stack <ll> topol;
ll num_c,c[N];

vector <ll> e3[N];
ll dp_par[N][K],dis[N],dp[2][N];

void dfs_dir(ll x)
{
	mark[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		ll ex=1;
		if(ed[e[x][i].second].second==x)ex=2;
		if(!dir[e[x][i].second])dir[e[x][i].second]=ex;
		if(!mark[e[x][i].first])dfs_dir(e[x][i].first);
	}
}

void dfs_topol(ll x)
{
	mark[x]=1;
	for(int i=0;i<e2[x].size();i++)
		if(!mark[e2[x][i]])
			dfs_topol(e2[x][i]);
	topol.push(x);
}

void dfs_rev(ll x)
{
	c[x]=num_c;
	for(int i=0;i<e_rev[x].size();i++)
		if(!c[e_rev[x][i]])
			dfs_rev(e_rev[x][i]);
}

void dfs_pre_lca(ll x,ll par=0)
{
	dp_par[x][0]=par;
	for(int i=1;i<K;i++)dp_par[x][i]=dp_par[dp_par[x][i-1]][i-1];
	for(int i=0;i<e3[x].size();i++)
		if(e3[x][i]!=par)
			dis[e3[x][i]]=dis[x]+1,dfs_pre_lca(e3[x][i],x);
}

ll Ipar(ll x,ll num)
{
	for(int i=0;i<K;i++,num/=2)
		if(num%2)
			x=dp_par[x][i];
	return x;
}

ll lca(ll x,ll y)
{
	//cout<<x<<" "<<y<<" ";
	if(dis[x]>dis[y])swap(x,y);
	//cout<<x<<" "<<y<<" "<<dis[y]-dis[x]<<" ";
	y=Ipar(y,dis[y]-dis[x]);
	//cout<<y<<"\n";
	if(y==x)return x;
	for(int i=K-1;i>=0;i--)
		if(dp_par[x][i]!=dp_par[y][i])
			x=dp_par[x][i],y=dp_par[y][i];
	return dp_par[x][0];
}

void dfs(ll x,ll par=0)
{
	for(int i=0;i<e3[x].size();i++)
		if(e3[x][i]!=par)
		{
			dfs(e3[x][i],x),dp[0][x]+=dp[0][e3[x][i]],dp[1][x]+=dp[1][e3[x][i]];
			if(dp[0][e3[x][i]]>0 && dp[1][e3[x][i]]>0){cout<<"No";exit(0);}
		}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back({u,i});
		e[u].push_back({v,i});
		ed.push_back({v,u});
	}
	dfs_dir(1);
	for(int i=0;i<N;i++)mark[i]=0;
	for(int i=0;i<m;i++)
	{
		if(dir[i]==1)e2[ed[i].first].push_back(ed[i].second),e_rev[ed[i].second].push_back(ed[i].first);
		else e2[ed[i].second].push_back(ed[i].first),e_rev[ed[i].first].push_back(ed[i].second);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs_topol(i);
	for(int i=0;i<N;i++)mark[i]=0;
	while(topol.size())
	{
		ll x=topol.top();topol.pop();
		if(c[x])continue;
		num_c++;
		dfs_rev(x);
	}
	for(int i=0;i<m;i++)
		if(c[ed[i].first]!=c[ed[i].second])
			e3[c[ed[i].first]].push_back(c[ed[i].second]),e3[c[ed[i].second]].push_back(c[ed[i].first]);
	dfs_pre_lca(1);
	for(int i=0;i<q;i++)
	{
		ll x,y;
		cin>>x>>y;
		x=c[x],y=c[y];
		ll p=lca(x,y);
		//cout<<x<<" "<<y<<" "<<p<<"\n";
		if(p==x)
			dp[1][x]--,
			dp[1][y]++;
		else if(p==y)
			dp[0][y]--,
			dp[0][x]++;
		else
			dp[0][p]--,
			dp[0][x]++,
			dp[1][p]--,
			dp[1][y]++;
	}
	dfs(1);
	cout<<"Yes";
	return 0;
}