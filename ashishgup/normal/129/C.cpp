#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=10;

int n=8;
set<int> g[N][N];
char a[N][N];
int cache[N][N][1000];
int dx[9]={-1, -1, -1, 0, 0, +1, +1, +1, 0};
int dy[9]={-1, 0, +1, -1, +1, -1, 0, +1, 0};

void work(int i, int j, int t)
{
	if(i>n)
		return;
	g[i][j].insert(t);
	work(i+1, j, t+1);
}

int dp(int i, int j, int t)
{
	if(i<1 || i>n || j<1 || j>n || t>=1000)
		return 0;
	if(i==1 && j==n)
		return 1;
	if(g[i][j].find(t)!=g[i][j].end())
		return 0;
	int &ans=cache[i][j][t];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int dir=0;dir<9;dir++)
	{
		int nx=i+dx[dir];
		int ny=j+dy[dir];
		if(g[nx][ny].find(t)==g[nx][ny].end())
			ans|=dp(nx, ny, t+1);
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='S')
				work(i, j, 0);
		}
	}
	int ans=dp(n, 1, 0);
	if(ans)
		cout<<"WIN";
	else
		cout<<"LOSE";
	return 0;
}