#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (1010)
#define INF ((ll)1e15)

ll n,m,color[N],d[N][N],mx[N],maxi,ans;
vector <ll> e[N];

void dfs(ll x)
{
	maxi=max(maxi,mx[x]);
	for(int i=0;i<e[x].size();i++)
	{
		if(color[e[x][i]]==color[x]){cout<<-1;exit(0);}
		if(!color[e[x][i]])color[e[x][i]]=((color[x]==1)?2:1),dfs(e[x][i]);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		queue <ll> q;d[i][i]=1;q.push(i);
		while(q.size())
		{
			ll x=q.front();q.pop();
			for(int j=0;j<e[x].size();j++)
				if(!d[i][e[x][j]])
					d[i][e[x][j]]=d[i][x]+1,q.push(e[x][j]);
		}
		for(int j=1;j<=n;j++)mx[i]=max(mx[i],d[i][j]-1);
	}
	for(int i=1;i<=n;i++)
		if(!color[i])
		{
			maxi=0;
			color[i]=1;
			dfs(i);
			ans+=maxi;
		}
	cout<<ans;	
    return 0;
}