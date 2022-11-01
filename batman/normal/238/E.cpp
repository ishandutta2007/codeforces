#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)105)
#define INF ((ll)1e9)

ll n,m,q,st,fn,dis[N][N];
ll s[N],t[N],d[N][N],out[N][N];
vector <ll> vec[N][N];
bool change[N][N],mark[N][N];
deque <pair<ll,ll> > qu;

int main()
{
	cin>>n>>m>>st>>fn;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dis[i][j]=d[i][j]=INF;
	for(int i=0;i<N;i++)dis[i][i]=0;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		dis[v][u]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>s[i]>>t[i];
		if(dis[s[i]][t[i]]>(ll)1e8)continue;
		for(int j=1;j<=n;j++)
		{
			ll d1=dis[s[i]][j],d2=dis[j][t[i]];
			if(d1+d2==dis[s[i]][t[i]])
				vec[i][d1].push_back(j);
		}
		for(int j=0;j<n;j++)
		{
			if(vec[i][j].size()==1)
				change[i][vec[i][j][0]]=1;
			for(auto v:vec[i][j])
				for(auto u:vec[i][j+1])
					if(dis[v][u]==1)
						out[i][v]++;
		}
		qu.push_back({i,fn});
		d[i][fn]=0;
	}
	while(qu.size())
	{
		ll x=qu.front().first,v=qu.front().second;qu.pop_front();
		if(mark[x][v])continue;
		mark[x][v]=1;
		if(change[x][v])
		{
			for(int i=0;i<q;i++)
				if(dis[s[i]][t[i]]<(ll)1e8 && d[i][v]>d[x][v]+1)
					qu.push_back({i,v}),
					d[i][v]=d[x][v]+1;
		}
		if(dis[s[x]][v]==0 || dis[s[x]][v]+dis[v][t[x]]!=dis[s[x]][t[x]])continue ;
		for(auto u:vec[x][dis[s[x]][v]-1])
			if(dis[u][v]==1)
			{
				out[x][u]--;
				if(out[x][u]==0 && d[x][u]>d[x][v])
					qu.push_front({x,u}),
					d[x][u]=d[x][v];
			}
	}
	ll ans=INF;
	for(int i=0;i<q;i++)
		if(change[i][st])
			ans=min(ans,d[i][st]+1);
	if(ans>(ll)1e8)return cout<<"-1\n",0;
	cout<<ans<<"\n";
	return 0;
}