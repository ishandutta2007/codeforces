#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m, mod;
int f[N];
int cache[N][N]; 

int dp(int x, int y) //x number of columns have zero 1s and y number of columns have one 1
{
	if(x==0 && y==0)
		return 1;
	int &ans=cache[x][y];
	if(ans!=-1)
		return ans;
	ans=0;
	if(x>1)
	{
		ans+=(x*(x-1)/2)*dp(x-2, y+2);
	}
	if(x>=1 && y>=1)
	{
		ans+=(x*y)*dp(x-1, y);
	}
	if(y>1)
	{
		ans+=(y*(y-1)/2)*dp(x, y-2);
	}
	ans%=mod;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>mod;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='1')
				f[j]++;
		}
	}
	int stx=0, sty=0;
	for(int i=1;i<=n;i++)
		stx+=(f[i]==0), sty+=(f[i]==1);
	int ans=dp(stx, sty);
	cout<<ans;
}