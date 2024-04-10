#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=155;

int n, m, ans=0, lastrow;
int first[N], last[N];
char a[N][N];

void dfs(int x, int y, int dir) //0=right, 1=left
{
	if(x>lastrow)
		return;
	if(dir==0)
	{
		int maxy=max(last[x], last[x+1]);
		maxy=max(y, maxy);
		ans+=maxy-y;
		dfs(x+1, maxy, dir^1);
	}
	else
	{
		int miny=min(first[x], first[x+1]);
		miny=min(y, miny);
		ans+=y-miny;
		dfs(x+1, miny, dir^1);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	lastrow=0;
	for(int i=1;i<=n;i++)
	{
		first[i]=m+1;
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='W')
			{
				lastrow=i;
				first[i]=min(first[i], j);
				last[i]=j;
			}
		}
	}	
	first[n+1]=m+1;
	dfs(1, 1, 0);
	ans+=max(0LL, lastrow-1);
	cout<<ans;
	return 0;
}