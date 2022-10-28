#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N=501;
const int M=251;
const int MOD=1e9+7;

int n, m;
char a[N][N];
int cache[N][N][M];

int dp(int x1, int x2, int moves)
{
	int y1=1 + (moves - (x1-1));
	int y2=m - (moves - (n-x2));
	if(x1>x2 || y1>y2 || a[x1][y1]!=a[x2][y2])
		return 0;
	if(x1==x2 && y2-y1<=1)
		return 1;
	if(y1==y2 && x2-x1<=1)
		return 1;
	int &ans=cache[x1][x2][moves];
	if(ans!=-1)
		return ans;
	ans=0;
	ans+=dp(x1+1, x2, moves+1);
	ans%=MOD;
	ans+=dp(x1, x2-1, moves+1);
	ans%=MOD;
	ans+=dp(x1, x2, moves+1);
	ans%=MOD;
	ans+=dp(x1+1, x2-1, moves+1);
	ans%=MOD;
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
	int ans=dp(1, n, 0);
	cout<<ans;
	return 0;
}