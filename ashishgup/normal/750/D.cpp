#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, ans=0;
int a[N];
bool mark[400][400];
bool vis[400][400][8][31];
int dx[8]={+1, +1, +1, 0, -1, -1, -1, 0};
int dy[8]={+1, 0, -1, -1, -1, 0, +1, +1};

void dfs(int i, int j, int dir, int k)
{
	if(k==n+1)
		return;
	if(vis[i][j][dir][k])
		return;
	vis[i][j][dir][k]=1;
	for(int p=0;p<=a[k];p++)
	{
		ans+=(mark[i+p*dx[dir]][j+p*dy[dir]]==0);
		mark[i+p*dx[dir]][j+p*dy[dir]]=1;
	}
	int lastx=i+a[k]*dx[dir];
	int lasty=j+a[k]*dy[dir];
	int dir1=(dir+1)%8;
	int dir2=(dir-1+8)%8;
	dfs(lastx+dx[dir1], lasty+dy[dir1], dir1, k+1);
	dfs(lastx+dx[dir2], lasty+dy[dir2], dir2, k+1);
}

int32_t main()
{
	IOS;
	memset(vis, 0, sizeof(vis));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	dfs(200, 200, 5, 1);
	cout<<ans;
}