#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int goal, n, m;
int rain[N], umbrella[N], cache[N][N];
pair<int, int> a[N], b[N];

int dp(int x, int y) 
{
	if(x==goal)
		return 0;
	int &ans=cache[x][y];
	if(ans!=-1)
		return ans;
	ans=1e15;
	if(umbrella[x])
		ans=dp(x, x);
	if(rain[x] && y==goal+1)
		return ans;
	if(rain[x])
		ans=min(ans, umbrella[y] + min(dp(x+1, y), dp(x+1, goal+1)));
	else
		ans=min(min(ans, dp(x+1, goal+1)), umbrella[y] + min(dp(x+1, y), dp(x+1, goal+1)));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>goal>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		for(int j=a[i].first;j<a[i].second;j++)
			rain[j]=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].first>>b[i].second;
		if(umbrella[b[i].first]==0)
			umbrella[b[i].first]=b[i].second;
		else
			umbrella[b[i].first]=min(umbrella[b[i].first], b[i].second);
	}
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	if(b[1].first>a[1].first)
	{
		cout<<"-1";
		return 0;
	}
	int ans=dp(0, goal+1);
	cout<<ans;
	return 0;
}