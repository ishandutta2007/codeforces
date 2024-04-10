#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m;
int vis[N][N];
char a[N][N];
int dx[8]={-1, -1, -1, 0, 0, +1, +1, +1};
int dy[8]={-1, 0, +1, +1, -1, -1, 0, +1};

int32_t main()
{
	IOS;
	cin>>n>>m;
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
			bool check=1;
			for(int k=0;k<8;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1 || x>n || j<1 || j>m)
				{
					check=0;
					break;
				}
				check&=(a[x][y]=='#');
			}
			if(check)
			{
				for(int k=0;k<8;k++)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					vis[x][y]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#' && !vis[i][j])
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}