#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int dp[5][N], dp2[5][N];
vector<int> g[5];
int cache[N][15];

int rec(int idx, int cur)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int take = 0; take <= 3; take++)
	{
		if(take > 0 && !dp[take][idx])
			continue;
		if(cur + take <= 9)
			ans = max(ans, dp[take][idx] + rec(idx + 1, cur + take));
		if(cur <= 9 && cur + take >= 10)
			ans = max(ans, dp2[take][idx] + rec(idx + 1, (cur + take) % 10));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= 3; j++)
			g[j].clear();
		for(int j = 1; j <= k; j++)
		{
			int c, d;
			cin >> c >> d;
			g[c].push_back(d);
		}
		for(int j = 1; j <= 3; j++)
			sort(g[j].rbegin(), g[j].rend());
		int sz1 = g[1].size();
		int sz2 = g[2].size();
		int sz3 = g[3].size();
		for(int ii = 0; ii <= min(3LL, sz1); ii++)
		{
			for(int j = 0; j <= min(1LL, sz2); j++)
			{
				for(int k = 0; k <= min(1LL, sz3); k++)
				{
					if(ii * 1 + j * 2 + k * 3 > 3)
						continue;
					int taken = ii + j + k;
					int damage = 0;
					int mx = 0;
					for(int l = 0; l < ii; l++)
					{
						mx = max(mx, g[1][l]);
						damage += g[1][l];
					}
					for(int l = 0; l < j; l++)
					{
						mx = max(mx, g[2][l]);
						damage += g[2][l];
					}
					for(int l = 0; l < k; l++)
					{
						mx = max(mx, g[3][l]);
						damage += g[3][l];
					}
					dp[taken][i] = max(dp[taken][i], damage);
					dp2[taken][i] = max(dp2[taken][i], damage + mx);
				}
			}
		}
	}
	int ans = rec(1, 0);
	cout << ans;
	return 0;
}