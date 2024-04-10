#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (3222)
#define INF ((ll)1e9)

ll n,m,d[N][N],x,y,l,x2,y2,l2;
vector <ll> e[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)d[i][j]=INF;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	cin>>x>>y>>l>>x2>>y2>>l2;
	for(int i=1;i<=n;i++)
	{
		queue <ll> q;
		bool mark[N]={};
		mark[i]=1;
		q.push(i);
		d[i][i]=0;
		while(q.size())
		{
			ll a=q.front();
			q.pop();
			for(int j=0;j<e[a].size();j++)
				if(!mark[e[a][j]])
					q.push(e[a][j]),d[i][e[a][j]]=d[i][a]+1,mark[e[a][j]]=1;	
		}
	}
	
	ll ans=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(d[x][i]+d[i][j]+d[j][y]<=l && d[x2][i]+d[i][j]+d[j][y2]<=l2)
				ans=min(ans,d[x][i]+d[x2][i]+d[i][j]+d[j][y]+d[j][y2]);	
			if(d[x][i]+d[i][j]+d[j][y]<=l && d[y2][i]+d[i][j]+d[j][x2]<=l2)
				ans=min(ans,d[x][i]+d[y2][i]+d[i][j]+d[j][y]+d[j][x2]);		
		}
			
				
	if(ans==INF && (d[x][y]>l || d[x2][y2]>l2))
		return cout<<-1,0;				
	cout<<m-((ans==INF)?d[x][y]+d[x2][y2]:min(ans,d[x][y]+d[x2][y2]));			
	
    return 0;
}