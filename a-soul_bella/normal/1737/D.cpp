#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int u[250005],v[500005],w[500005];
int dis[505][505];
const int inf=1e18;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dis[i][j]=1e9;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int i=1;i<=m;i++)
		{
			cin >> u[i] >> v[i] >> w[i];
			dis[u[i]][v[i]]=min(dis[u[i]][v[i]],1ll);
			dis[v[i]][u[i]]=min(dis[v[i]][u[i]],1ll);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int ans=inf;
		for(int i=1;i<=m;i++)
		{
			ans=min(ans,(min(dis[u[i]][n]+dis[v[i]][1],dis[v[i]][n]+dis[u[i]][1])+1)*w[i]);
			for(int x=1;x<=n;x++)
			{
				int X=dis[u[i]][x]+dis[x][1]+dis[x][n]+2;
				int Y=dis[v[i]][x]+dis[x][1]+dis[x][n]+2;
				ans=min(ans,(min(X,Y)*w[i]));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}