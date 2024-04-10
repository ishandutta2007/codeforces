#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int vis[N];
char g[N][N];

void dfs(int k, int par)
{
	if(vis[k])
		return;
	vis[k]=1;
	for(int i=1;i<=n;i++)
	{
		if(g[k][i]=='0')
			continue;
		dfs(i, k);
		if(g[i][par]=='1')
		{
			cout<<par<<" "<<k<<" "<<i;
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		dfs(i, 0);
	cout<<"-1";
	return 0;    
}