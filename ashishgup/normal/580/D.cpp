#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=18;

int n, m, k, ans=0;
int a[N+1];
int g[N+1][N+1];
int cache[1LL<<N][N+1];

int dp(int mask, int last)
{
	if(__builtin_popcount(mask)==m)
		return 0;
	int &ans=cache[mask][last];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!(mask&(1<<(i-1))))
			ans=max(ans, a[i] + g[last][i] + dp(mask|(1<<(i-1)), i));
	}	
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
	{
		int x, y, c;
		cin>>x>>y>>c;
		g[x][y]=c;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans, a[i] + dp(1<<(i-1), i));
	cout<<ans;
	return 0;
}