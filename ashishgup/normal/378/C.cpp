#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m, k, s=0;
char a[N][N], ans[N][N];
int vis[N][N];
int dx[4]={+1, -1, 0, 0};
int dy[4]={0, 0, +1, -1};

void dfs(int i, int j)
{
	if(k==0 || i<1 || j<1 || i>n || j>m)
		return;
	if(vis[i][j])
		return;
	if(a[i][j]=='#')
		return;
	vis[i][j]=1;
	ans[i][j]='.';
	k--;
	for(int dir=0;dir<4;dir++)
	{
		dfs(i+dx[dir], j+dy[dir]);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			ans[i][j]=a[i][j];
			if(a[i][j]=='.')
			{
				s++;
				ans[i][j]='X';
			}
		}
	}
	k=s-k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
				dfs(i, j);
		}		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}