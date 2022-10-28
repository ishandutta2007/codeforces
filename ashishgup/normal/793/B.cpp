#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, m, sti, stj, check=0;
char a[N][N];
bool vis[N][N][4][3];
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};

void dfs(int i, int j, int dir, int turns)
{
	if(turns>2)
		return;
	if(i>n || j>m || i<1 || j<1)
		return;
	if(a[i][j]=='*')
		return;
	if(a[i][j]=='T')
	{
		check=1;
		return;
	}
	if(vis[i][j][dir][turns])
		return;
	vis[i][j][dir][turns]=1;
	for(int k=0;k<4;k++)
		dfs(i+dx[k], j+dy[k], k, turns+(k!=dir));
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
			if(a[i][j]=='S')
				sti=i, stj=j;
		}
	}
	dfs(sti, stj, 0, 0);
	dfs(sti, stj, 1, 0);
	dfs(sti, stj, 2, 0);
	dfs(sti, stj, 3, 0);
	if(check)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;   
}