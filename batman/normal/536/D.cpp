#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)2010)
#define INF ((ll)1e18)

ll n,m,s,t,a[N],dp[N][N][2],dist[2][N];
vector <pair<ll,ll> > e[N];
pair <ll,ll> dis[2][N];

void dij(ll x,bool p)
{
	set <pair<ll,ll> > s;
	dis[p][0].first=-1;dis[p][n+1].first=INF;
	for(int i=1;i<=n;i++)dis[p][i]={INF,i};
	dis[p][x].first=0;s.insert({0,x});
	while(s.size())
	{
		ll v=s.begin()->second;s.erase(s.begin());
		for(auto u:e[v])
			if(dis[p][u.first].first>dis[p][v].first+u.second)
				s.erase({dis[p][u.first].first,u.first}),dis[p][u.first].first=dis[p][v].first+u.second,s.insert({dis[p][u.first].first,u.first});
	}
	sort(dis[p]+1,dis[p]+n+1);
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
    	ll v,u,w;
    	cin>>v>>u>>w;
    	e[v].push_back({u,w});
    	e[u].push_back({v,w});
	}
	dij(s,0);dij(t,1);
	for(int i=1;i<=n;i++)dist[0][dis[0][i].second]=dis[0][i].first,dist[1][dis[1][i].second]=dis[1][i].first;
	for(int i=n;i>=0;i--)
		for(int j=n;j>=0;j--)
		{
			// 0
			ll v=dis[0][i+1].second;
			if(dist[1][v]<=dis[1][j].first)dp[i][j][0]=dp[i+1][j][0];
			else if(dis[0][i+1].first==dis[0][i+2].first)dp[i][j][0]=a[v]+dp[i+1][j][0];
			else dp[i][j][0]=max(dp[i+1][j][0],(j!=n)?dp[i+1][j][1]:-INF)+a[v];
			// 1
			v=dis[1][j+1].second;
			if(dist[0][v]<=dis[0][i].first)dp[i][j][1]=dp[i][j+1][1];
			else if(dis[1][j+1].first==dis[1][j+2].first)dp[i][j][1]=-a[v]+dp[i][j+1][1];
			else dp[i][j][1]=min((i!=n)?dp[i][j+1][0]:INF,dp[i][j+1][1])-a[v];
		}
	if(!dp[0][0][0])cout<<"Flowers";
	else cout<<(dp[0][0][0]>0?"Break a heart":"Cry");
	return 0;
}