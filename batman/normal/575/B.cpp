#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define K (60)
#define MOD ((ll)1e9+7)

ll n,k,c,comp[N],par[N][K],dis[N],sum[2][N],ans;
vector <ll> e[N];
vector <pair<ll,bool> > e2[N];
vector <pair<ll,ll> > vec;
bool mark[N];

void dfs3(ll x)
{
	mark[x]=1;
	for(int i=0;i<e2[x].size();i++)
		if(!mark[e2[x][i].first])
		{
			dfs3(e2[x][i].first);
			sum[0][x]+=sum[0][e2[x][i].first];sum[1][x]+=sum[1][e2[x][i].first];
			if(e2[x][i].second)
				ans+=tavan(2,sum[1][e2[x][i].first],MOD)-1+MOD,ans%=MOD;
			else
				ans+=tavan(2,sum[0][e2[x][i].first],MOD)-1+MOD,ans%=MOD;
		}
}

void dfs(ll x)
{
	mark[x]=1;comp[x]=c;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs(e[x][i]);
}

void dfs2(ll x)
{
	mark[x]=1;
	for(int i=1;i<K;i++)
		par[x][i]=par[par[x][i-1]][i-1];
	for(int i=0;i<e2[x].size();i++)
		if(!mark[e2[x][i].first])
			dis[e2[x][i].first]=dis[x]+1,par[e2[x][i].first][0]=x,dfs2(e2[x][i].first);
	mark[x]=0;
}

ll iPar(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=par[x][i];
	return x;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	if(iPar(x,dis[x]-dis[y])==y)return y;
	x=iPar(x,dis[x]-dis[y]);
	for(int i=K-1;i>=0;i--)
		if(par[x][i]!=par[y][i])
			x=par[x][i],y=par[y][i];
	return par[x][0];
}

int main()
{ 
	scanf("%I64d",&n);
    for(int i=0;i<n-1;i++)
    {
    	ll v,u,p;
    	scanf("%I64d%I64d%I64d",&v,&u,&p);
    	if(p)vec.push_back({v,u});
    	else e[v].push_back(u),e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			c++;
			dfs(i);
		}
			
	for(int i=0;i<vec.size();i++)
		e2[comp[vec[i].first]].push_back({comp[vec[i].second],0}),e2[comp[vec[i].second]].push_back({comp[vec[i].first],1});
	for(int i=0;i<N;i++)mark[i]=0;
	dfs2(1);
	scanf("%I64d",&k);
	ll now=comp[1];
	while(k--)
	{
		ll x,p;
		scanf("%I64d",&x);
		x=comp[x];
		p=lca(x,now);
		if(p==now)sum[1][now]--,sum[1][x]++;
		else if(p==x)sum[0][x]--,sum[0][now]++;
		else
		{
			sum[0][p]--,sum[0][now]++;
			sum[1][p]--,sum[1][x]++;
		}
		now=x;
	}
	dfs3(1);
	printf("%I64d",ans);
    return 0;
}