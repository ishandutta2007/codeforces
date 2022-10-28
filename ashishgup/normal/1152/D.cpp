#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int n;
int cache[2 * N][N][2];

int dp(int idx, int bal, int taken)
{
	if(idx == 2 * n + 1)
		return 0;
	int &ans = cache[idx][bal][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int left = 2 * n - idx;
	if(!taken)
	{
		ans = 0;
		if(bal + 1 <= left && bal - 1 >= 0)
		{
			ans = 1;
			ans += dp(idx + 1, bal + 1, 1);
			ans += dp(idx + 1, bal - 1, 0);
		}
		else if(bal + 1 <= left)
		{
			ans = 1;
			ans += dp(idx + 1, bal + 1, 1);
		}
		else if(bal - 1 >= 0)
		{
			ans = 1;
			ans += dp(idx + 1, bal - 1, 1);
		}
	}
	else
	{
		ans = 0;
		if(bal + 1 <= left)
			ans += dp(idx + 1, bal + 1, 0);
		if(bal - 1 >= 0)	
			ans += dp(idx + 1, bal - 1, 0);
	}
	ans %= MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	int ans = dp(1, 0, 0);
	cout << ans;
	return 0;
}