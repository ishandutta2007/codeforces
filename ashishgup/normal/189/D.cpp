#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=61;

int n, m, r;
int dist[N][N][N], cache[N][N][N];
int ans[N][N][N];

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				cin>>dist[i][j][k];
		}
	}
	for(int car=1;car<=m;car++)
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dist[car][i][j]=min(dist[car][i][j], dist[car][i][k] + dist[car][k][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i][j][0]=2e9;
			for(int car=1;car<=m;car++)
				ans[i][j][0]=min(ans[i][j][0], dist[car][i][j]);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j][k]=2e9;
				for(int mid=1;mid<=n;mid++)
					ans[i][j][k]=min(ans[i][j][k], ans[i][mid][k-1] + ans[mid][j][0]);
			}
		}
	}
	while(r--)
	{
		int s, t, k;
		cin>>s>>t>>k;
		k=min(n, k);
		int answer=ans[s][t][k];
		cout<<answer<<endl;
	}
	return 0;
}