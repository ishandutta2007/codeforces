#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, ans=0;
char a[N][N];
int dx[5]={0, -1, -1, +1, +1};
int dy[5]={0, +1, -1, +1, -1};

bool check(int x, int y)
{
	if(x<1 || x>n || y<1 || y>n || a[x][y]=='.')
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool cur=1;
			for(int dir=0;dir<5;dir++)
			{
				int nx=i + dx[dir];
				int ny=j + dy[dir];
				cur&=check(nx, ny);
			}
			ans+=cur;
		}
	}
	cout<<ans;
	return 0;
}