#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+17)

int n,m,b,c;
ll d[2][N],num[2][N];
vector <pair<int,int> > e[N],e2[N];
pair <pair<int,int>,int> ed[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>b>>c;
	for(int i=1;i<=m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed[i]={{v,u},w};
		e[v].push_back({u,w});
		e2[u].push_back({v,w});
	}
	for(int i=0;i<N;i++)if(i!=b)d[0][i]=INF;
	set <pair<ll,ll> > s;s.insert({0,b});num[0][b]=1;
	while(s.size())
	{
		int x=s.begin()->second;s.erase(s.begin());
		for(int i=0;i<e[x].size();i++)
		{
			if(d[0][e[x][i].first]>d[0][x]+e[x][i].second)num[0][e[x][i].first]=num[0][x],s.erase({d[0][e[x][i].first],e[x][i].first}),d[0][e[x][i].first]=d[0][x]+e[x][i].second,s.insert({d[0][e[x][i].first],e[x][i].first});
			else if(d[0][e[x][i].first]==d[0][x]+e[x][i].second)num[0][e[x][i].first]+=num[0][x],num[0][e[x][i].first]%=MOD;
		}
	}
	for(int i=0;i<N;i++)if(i!=c)d[1][i]=INF;
	s.insert({0,c});num[1][c]=1;
	while(s.size())
	{
		int x=s.begin()->second;s.erase(s.begin());
		for(int i=0;i<e2[x].size();i++)
		{
			if(d[1][e2[x][i].first]>d[1][x]+e2[x][i].second)num[1][e2[x][i].first]=num[1][x],s.erase({d[1][e2[x][i].first],e2[x][i].first}),d[1][e2[x][i].first]=d[1][x]+e2[x][i].second,s.insert({d[1][e2[x][i].first],e2[x][i].first});
			else if(d[1][e2[x][i].first]==d[1][x]+e2[x][i].second)num[1][e2[x][i].first]+=num[1][x],num[1][e2[x][i].first]%=MOD;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int v=ed[i].first.first,u=ed[i].first.second,w=ed[i].second;
		if(d[0][v]+w+d[1][u]==d[0][c] && ((num[0][v]*num[1][u])%MOD==num[0][c])){cout<<"YES\n";continue;}
		if(d[0][v]+1+d[1][u]<d[0][c]){cout<<"CAN "<<w-d[0][c]+d[0][v]+d[1][u]+1<<"\n";continue;}
		cout<<"NO\n";
	}
    return 0;
}