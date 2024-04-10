#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=55;

int n, m;
int vis[N][N][4][2], vis2[N][N];
char a[N][N];
int dx[4]={+1, -1, 0, 0};
int dy[4]={0, 0, +1, -1};

void dfs(int i, int j, int dir, int changed)
{
	if(changed>1 || i>n || i<1 || j<1 || j>m)
		return;
	if(vis[i][j][dir][changed] || a[i][j]=='W')
		return;
	vis[i][j][dir][changed]=1;
	vis2[i][j]=1;
	for(int k=0;k<4;k++)
		dfs(i+dx[k], j+dy[k], k, changed+(dir!=k));
}


int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='B')
			{
				memset(vis, 0, sizeof(vis));
				memset(vis2, 0, sizeof(vis2));
				vis2[i][j]=1;
				for(int k=0;k<4;k++)
					dfs(i+dx[k], j+dy[k], k, 0);
				bool check=1;
				for(int p=1;p<=n;p++)
					for(int q=1;q<=m;q++)
						if(a[p][q]=='B')
							check&=(vis2[p][q]);
				if(!check)
				{
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
	return 0;
}