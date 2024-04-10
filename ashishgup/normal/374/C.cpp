#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, m;
char a[N][N];
bool rec[N][N][4];
int cache[N][N][4];
int dx[4]={0, 0, +1, -1};
int dy[4]={+1, -1, 0, 0};
char b[4]={'D','I','M','A'};

int dp(int i, int j, int prev)
{
	if(i<1||i>n||j<1||j>m)
		return 0;
	if(rec[i][j][prev])
		return 1e9;
	char cur=(b[(prev+1)%4]);
	if(a[i][j]!=cur)
		return 0;
	int &ans=cache[i][j][prev];
	if(ans!=-1)
		return ans;
	rec[i][j][prev]=1;
	ans=0;
	int val=0;
	if(prev==2)
		val=1;
	for(int k=0;k<4;k++)
	{
		ans=max(ans, val + dp(i+dx[k], j+dy[k], (prev+1)%4));
	}
	rec[i][j][prev]=0;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans, dp(i, j, 3));
	if(!ans)
		cout<<"Poor Dima!";
	else if(ans>n*m)
		cout<<"Poor Inna!";
	else
		cout<<ans;
	return 0;
}