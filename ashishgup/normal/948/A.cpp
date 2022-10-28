#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n, m;
int vis[N][N];
char a[N][N];

void dfs(int i, int j)
{
	if(i<1 || j<1 || i>n || j>m)
		return;
	if(a[i][j]=='D')
		return;
	if(a[i][j]=='S')
	{
		cout<<"No";
		exit(0);
	}
	if(vis[i][j])
		return;
	vis[i][j]=1;
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='.')
				a[i][j]='D';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='W')
			{
				dfs(i, j);
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}