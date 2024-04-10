#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)5050)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m,k,dp[N][N],par[N][N];
vector <pair<ll,ll> > e[N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dp[i][j]=INF;
	dp[1][1]=0;
	par[1][1]=-1;
	queue <pair<ll,ll> > q;
	q.push({1,1});
	while(q.size())
	{
		ll x=q.front().first,p=q.front().second;q.pop();
		for(auto v:e[x])
			if(dp[x][p]+v.second<dp[v.first][p+1])
				dp[v.first][p+1]=dp[x][p]+v.second,par[v.first][p+1]=x,q.push({v.first,p+1});
	}
	ll x=n,p;
	for(int i=2;i<=n;i++)
		if(dp[n][i]<=k)
			p=i;
	cout<<p<<"\n";
	stack <ll> st;
	while(x!=-1)
		st.push(x),x=par[x][p--];
	while(st.size())cout<<st.top()<<" ",st.pop();
	return 0;
}