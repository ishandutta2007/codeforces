#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, m;
int a[N][N];

bool square(int x, int y)
{
	if(x<0 || y<0)
		return 0;
	for(int i=x;i<=x+2;i++)
		for(int j=y;j<=y+2;j++)
			if(!a[i][j])
				return 0;
	return 1;
}

bool check(int x, int y)
{
	for(int i=x-2;i<=x;i++)
		for(int j=y-2;j<=y;j++)
			if(square(i, j))
				return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		a[x][y]=1;
		if(check(x, y))
		{
			cout<<i;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}