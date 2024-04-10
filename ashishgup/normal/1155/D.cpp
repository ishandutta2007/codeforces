#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, x;
int a[N];
int cache[N][3];

int dp(int idx, int cur)
{
	if(idx == n + 1)
		return 0;
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	ans = 0;
	if(cur == 0)
	{
		ans = max(ans, a[idx] + dp(idx + 1, 0));
		ans = max(ans, x * a[idx] + dp(idx + 1, 1));
	}
	else if(cur == 1)
	{
		ans = max(ans, x * a[idx] + dp(idx + 1, 1));
		ans = max(ans, a[idx] + dp(idx + 1, 2));
	}
	else
		ans = max(ans, a[idx] + dp(idx + 1, 2));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp(i, 0));
	cout << ans;
	return 0;
}