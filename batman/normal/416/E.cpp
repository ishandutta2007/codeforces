#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (505)
#define INF ((ll)1e9)

ll n,m,d[N][N],num[N][N];
vector <pair<ll,ll> > e[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j)d[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		set <pair<ll,ll> > s;s.insert({0,i});
		while(s.size())
		{
			ll x=s.begin()->second;s.erase(s.begin());
			for(int j=0;j<e[x].size();j++)
			{
				if(d[i][e[x][j].first]>d[i][x]+e[x][j].second)num[i][e[x][j].first]=1,s.erase({d[i][e[x][j].first],e[x][j].first}),d[i][e[x][j].first]=d[i][x]+e[x][j].second,s.insert({d[i][e[x][j].first],e[x][j].first});
				else if(d[i][e[x][j].first]==d[i][x]+e[x][j].second)num[i][e[x][j].first]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			ll res=0;
			for(int k=1;k<=n;k++)
				if(d[i][k]+d[k][j]==d[i][j])
					res+=num[i][k];
			cout<<res<<" ";
		}
			
    return 0;
}