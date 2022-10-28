#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

const int N = 1e5 + 5;

int n, m;
string s;
int cnt[20][20];
int cache[20][1 << 20], cache2[1 << 20];

int dp2(int mask)
{
	int &ans = cache2[mask];
	if(ans != -1)
		return ans;
	int cost = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			if((mask >> i & 1) ^ (mask >> j & 1))
				cost += cnt[i][j];
		}
	}
	return ans = cost;
}

int dp(int idx, int mask)
{
	if(idx == m)
		return 0;
	int &ans = cache[idx][mask];
	if(ans != -1)
		return ans;
	int cost = dp2(mask);
	ans = 1e9;
	for(int i = 0; i < m; i++)
	{
		if(mask >> i & 1)
			continue;
		ans = min(ans, dp(idx + 1, mask | (1 << i)));
	}
	ans += cost;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n >> m;
	cin >> s;
	for(int i = 0; i + 1 < s.size(); i++)
	{
		cnt[s[i] - 'a'][s[i + 1] - 'a']++;
		cnt[s[i + 1] - 'a'][s[i] - 'a']++;
	}
	int ans = dp(0, 0);
	cout << ans;
	return 0;
}