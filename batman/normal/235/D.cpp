#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#define ll int
#define ld long double
#define N ((ll)3030)
#define K ((ll)12)

ll n,mark[N],pos[N],dp[K][N],dis[N];
ld ans;
vector <ll> e[N],now,cycle;
bool dead[N];

void dfs_cycle(ll x,ll par=0)
{
	mark[x]=1;
	now.push_back(x);
	for(auto u:e[x])
	{
		if(u==par || mark[u]==2)continue;
		if(mark[u])
		{
			for(int i=(ll)now.size()-1;i>=0;i--)
			{
				dead[now[i]]=1;
				pos[now[i]]=cycle.size();
				cycle.push_back(now[i]);
				if(now[i]==u)break;
			}
			continue;
		}
		dfs_cycle(u,x);
	}
	mark[x]=2;
}

void pre_dfs(ll x,ll id)
{
	pos[x]=id;
	for(int i=1;i<K;i++)dp[i][x]=dp[i-1][dp[i-1][x]];
	for(auto u:e[x])
		if(!dead[u] && u!=dp[0][x])
			dis[u]=dis[x]+1,
			dp[0][u]=x,
			pre_dfs(u,id);
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=dp[i][x];
	return x;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(dp[i][x]!=dp[i][y])
			x=dp[i][x],y=dp[i][y];
	return dp[0][x];
}


int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll v,u;
		cin>>v>>u;v++;u++;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs_cycle(1);
	for(auto u:cycle)pre_dfs(u,pos[u]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(pos[i]==pos[j])
			{
				ans+=(ld)1/(dis[i]+dis[j]-2*dis[lca(i,j)]+1);
				continue;
			}
			ll p=abs(pos[i]-pos[j]),q=(ll)cycle.size()-p;
			ans+=(ld)1/(dis[i]+dis[j]+p+1)+(ld)1/(dis[i]+dis[j]+q+1)-(ld)1/(dis[i]+dis[j]+p+q);
		}
	ans*=2;ans+=n;
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}