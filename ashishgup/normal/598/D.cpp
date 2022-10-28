#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N=1005;

int n, m, k, peri=0;
int ans[N][N], vis[N][N];
char a[N][N];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
vector<pair<int ,int> > v;

void dfs(int i, int j)
{
	if(i<1 || j<1 || i>n || j>m)
		return;
	if(vis[i][j])
		return;
	if(a[i][j]=='*')
	{
		peri++;
		return;
	}
	vis[i][j]=1;
	v.push_back({i, j});
	for(int k=0;k<4;k++)
		dfs(i+dx[k], j+dy[k]);
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
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.'&&!vis[i][j])
			{
				v.clear();
				peri=0;
				dfs(i, j);
				for(auto it:v)
				{
					ans[it.first][it.second]=peri;
				}
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		int x, y;
		cin>>x>>y;
		cout<<ans[x][y]<<endl;
	}
	return 0;
}