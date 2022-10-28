#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m;
int ax, ay, bx, by;
char a[N][N];
bool vis[N][N];
int dx[4]={0, 0, -1, +1};
int dy[4]={-1, +1, 0, 0};

void dfs(int x, int y)
{
	if(x<1 || x>n || y<1 || y>m || vis[x][y] || a[x][y]=='X')
		return;
	vis[x][y]=1;
	for(int dir=0;dir<4;dir++)
		dfs(x+dx[dir], y+dy[dir]);
}

void check()
{	
	memset(vis, 0, sizeof(vis));
	dfs(ax, ay);
	if(vis[bx][by])
	{
		cout<<"YES";
		exit(0);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>ax>>ay;
	a[ax][ay]='.';
	cin>>bx>>by;
	if(a[bx][by]=='X')
	{
		a[bx][by]='.';
		check();
	}
	else
	{
		for(int dir=0;dir<4;dir++)
		{
			int nx=bx+dx[dir];
			int ny=by+dy[dir];
			if(a[nx][ny]=='.')
			{
				a[nx][ny]='X';
				check();
				a[nx][ny]='.';
			}
		}
	}
	cout<<"NO";
	return 0;
}