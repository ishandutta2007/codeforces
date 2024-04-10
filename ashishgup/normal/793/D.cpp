#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=81;
const int M=2001;

int n, k, m, ans=1e9;
int cache[N][2][N][N];
vector<pair<int, int> > g[N];

int dp(int idx, int dir, int dist, int taken)
{
	if(taken==k)
		return 0;
	int &ans=cache[idx][dir][dist][taken];
	if(ans!=-1)
		return ans;
	ans=1e9;
	for(auto &it:g[idx])
	{
		if(abs(it.first-idx)<=dist)
		{
			if((it.first-idx>0 && dir>0) || (idx-it.first>0 && dir==0))
			{
				ans=min(ans, it.second + min(dp(it.first, dir, dist-abs(it.first-idx), taken+1), dp(it.first, dir^1, abs(it.first-idx)-1, taken+1)));
			}
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		g[u].push_back({v, c});
	}	
	for(int i=1;i<=n;i++)
		ans=min(ans, min(dp(i, 1, n-i, 1), dp(i, 0, i-1, 1)));
	if(ans>1e8)
		ans=-1;
	cout<<ans;
	return 0;
}