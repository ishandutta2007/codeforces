#include <bits/stdc++.h>
using namespace std;
#define ll int
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define K (60)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,p,dp[2][N];
vector <ll> e[N];
map <ll,ll> mp;
bool mark[N];

bool check(ll x)
{
	while(x)
	{
		if(x%10!=4 && x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

void dfs(ll x)
{
	mark[x]=1;p++;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dfs(e[x][i]);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			p=0;
			dfs(i);
			mp[p]++;
		}
	for(int i=1;i<=n;i++)dp[0][i]=INF;
	bool y=1;
	for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++,y=!y)
	{
		ll x=it->first,num=it->second;
		for(int i=0;i<x;i++)
		{
			deque <pair<ll,ll> > q;
			for(int j=i;j<=n;j+=x)
			{
				dp[y][j]=dp[!y][j];
				if(q.size())
				{
					if(q.front().first<j-num*x)q.pop_front();
					dp[y][j]=min(dp[y][j],q.front().second+(j-i)/x);
				}
				ll now=dp[!y][j]-(j-i)/x;
				while(q.size() && q.back().second>=now)q.pop_back();
				q.push_back({j,now});
			}
		}
	}
	ll ans=INF;
	for(int i=1;i<=n;i++)
		if(check(i))
			ans=min(ans,dp[!y][i]);
	if(ans==INF)cout<<-1;
	else cout<<ans-1;
    return 0;
}