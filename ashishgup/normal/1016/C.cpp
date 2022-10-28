#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, ans=0;
int a[3][N];
int pref[3][N], suf[3][N], p[3][N], s[3][N];

void dfs(int x, int y, int val, int day=0)
{
	ans=max(ans, val);
	if(y>n)
		return;
	if(y%2)
	{
		if(x==1)
			dfs(x+1, y, val+a[x][y]*day, day+1);
		else
			dfs(x, y+1, val+a[x][y]*day, day+1);
	}
	else
	{
		if(x==2)
			dfs(x-1, y, val+a[x][y]*day, day+1);
		else
			dfs(x, y+1, val+a[x][y]*day, day+1);
	}
	if(x%2 && y%2)
	{
		int curval=pref[1][n]-pref[1][y-1]+(day-y)*(p[1][n]-p[1][y-1]);
		curval+=suf[2][y]+(day+n-y)*(p[2][n]-p[2][y-1]);
		ans=max(ans, val+curval);
	}
	else if(y%2==1)
	{
		int curval=pref[2][n]-pref[2][y-1]+(day-y)*(p[2][n]-p[2][y-1]);
		curval+=suf[1][y+1]+(day+n-y)*(p[1][n]-p[1][y]);
		ans=max(ans, val+curval);
	}
	else if(x%2)
	{
		int curval=pref[1][n]-pref[1][y-1]+(day-y)*(p[1][n]-p[1][y-1]);
		curval+=suf[2][y+1]+(day+n-y)*(p[2][n]-p[2][y]);
		ans=max(ans, val+curval);
	}
	else
	{
		int curval=pref[2][n]-pref[2][y-1]+(day-y)*(p[2][n]-p[2][y-1]);
		curval+=suf[1][y]+(day+n-y)*(p[1][n]-p[1][y-1]);
		ans=max(ans, val+curval);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			pref[i][j]=pref[i][j-1]+j*a[i][j];
			p[i][j]=p[i][j-1]+a[i][j];
		}
		for(int j=n;j>=1;j--)
		{
			s[i][j]=s[i][j+1]+a[i][j];
			suf[i][j]=suf[i][j+1]+(n-j+1)*a[i][j];
		}
	}
	dfs(1, 1, 0);
	cout<<ans;
	return 0;
}