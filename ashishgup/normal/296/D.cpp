#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n;
int a[N], ans[N], vis[N];
int dist[N][N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dist[i][j];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int idx=n;idx>=1;idx--)
	{
		int k=a[idx];
		vis[k]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
				if(vis[i] && vis[j])
					ans[idx]+=dist[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}