#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 4e5 + 5;
 
int n;
int a[N];
int cache[1 << 20];
int cost[50][50];
 
void work(int i, int j)
{
	int cnt = 0;
	for(int k = 1; k <= n; k++)
	{
		if(a[k] == j)
			cnt++;
		if(a[k] == i)
			cost[i][j] += cnt;
	}
}
 
int dp(int mask)
{
	if(mask == ((1 << 20) - 1))
		return 0;
	int &ans = cache[mask];
	if(ans != -1)
		return ans;
	ans = 1e15;
	for(int i = 0; i < 20; i++)
	{
		if(mask >> i & 1)
			continue;
		int curCost = 0;
		for(int j = 0; j < 20; j++)
		{
			if(mask >> j & 1)
				curCost += cost[j][i];
		}
		curCost += dp(mask | (1 << i));
		ans = min(ans, curCost);
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
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			if(i != j)
				work(i, j);
	int ans = dp(0);
	cout << ans;
	return 0;
}