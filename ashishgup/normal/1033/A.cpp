#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, ax, ay, bx, by, cx, cy;
int vis[N][N];
int dx[8]={-1, -1, -1, 0, 0, +1, +1, +1};
int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};

bool attack(int x, int y)
{
	if(x==ax)
		return 1;
	if(y==ay)
		return 1;
	int xdiff=abs(x-ax);
	int ydiff=abs(y-ay);
	if(xdiff==ydiff)
		return 1;
	return 0;
}

void dfs(int x, int y)
{
	if(x<1 || y<1 || x>n || y>n)
		return;
	if(vis[x][y])
		return;
	if(attack(x, y))
		return;
	vis[x][y]=1;
	for(int k=0;k<8;k++)
	{
		dfs(x+dx[k], y+dy[k]);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
	dfs(bx, by);
	if(vis[cx][cy])
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}