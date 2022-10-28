#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, ctr;
int a[N][N], vis[N][N], vis2[N][N];
int cache[N][N], cache2[N][N];
int val;

int get(int x, int y) //5 // 3
{
	if(x < y)
		return 2e18;
	return x - y;
}

int dp(int i, int j, int dist)
{
	if(i > n || j > m)
		return 2e18;
	if(i == n && j == m)
		return get(a[i][j], val + dist);
	int &ans = cache[i][j];
	if(vis[i][j] == ctr)
		return ans;
	vis[i][j] = ctr;
	ans = get(a[i][j], val + dist) + min(dp(i + 1, j, dist + 1), dp(i, j + 1, dist + 1));
	ans = min(ans, (int)2e18);
	return ans;
}

int dp2(int i, int j, int dist)
{
	if(i < 1 || j < 1)
		return 2e18;
	if(i == 1 && j == 1)
		return get(a[i][j], val - dist);
	int &ans = cache2[i][j];
	if(vis2[i][j] == ctr)
		return ans;
	vis2[i][j] = ctr;
	ans = get(a[i][j], val - dist) + min(dp2(i - 1, j, dist + 1), dp2(i, j - 1, dist + 1));
	ans = min(ans, (int)2e18);
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		int ans = 8e18;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				++ctr;
				val = a[i][j];
				int cur = dp(i, j, 0) + dp2(i, j, 0);
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	return 0;
}