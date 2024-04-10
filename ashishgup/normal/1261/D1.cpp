#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2005;
const int MOD = 998244353;

int n, k;
int a[N];
int cache[N][N + N];

int dp(int i, int diff)
{
	if(i >= n)
		return (diff > 0);
	int &ans = cache[i][diff + N];
	if(ans != -1)
		return ans;
	if(a[i] == a[(i + 1) % n])
		ans = (k * dp(i + 1, diff)) % MOD;
	else
	{
		ans = dp(i + 1, diff - 1) + dp(i + 1, diff + 1);
		ans += (k - 2) * dp(i + 1, diff);
		ans %= MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	if(n == 1 || k == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = dp(0, 0);
	cout << ans;
	return 0;
}