#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2005;

int n, h, l, r;
int a[N];
int cache[N][N];

int dp(int idx, int cur)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int newT = a[idx] - 1; newT <= a[idx]; newT++)
	{
		int tim = (newT + cur) % h;
		int curVal = (tim >= l && tim <= r) + dp(idx + 1, tim);
		ans = max(ans, curVal);
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> h >> l >> r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = dp(1, 0);
	cout << ans;
	return 0;
}