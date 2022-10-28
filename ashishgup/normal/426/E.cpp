#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, m, s, e, mx, ans = 0;
int a[N], b[N], dp[305], ndp[305];
set<int> pos[N];
 
int32_t main()
{
	IOS;
	cin >> n >> m >> s >> e;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		cin >> b[i];
		pos[b[i]].insert(i);
	}
	mx = s / e;
	for(int i = 1; i <= mx; i++)
		dp[i] = 1e9;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= mx; j++)
			ndp[j] = dp[j];
		for(int j = 1; j <= mx; j++)
		{
			int idx = dp[j - 1];
			auto it = pos[a[i]].upper_bound(idx);
			if(it != pos[a[i]].end())
			{
				ndp[j] = min(ndp[j], *it);
				int left = s - e * j;
				if(left >= i + *it)
					ans = max(ans, j);
			}
		}
		for(int j = 0; j <= mx; j++)
			dp[j] = ndp[j];
	}
	cout << ans;
	return 0;
}