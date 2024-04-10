#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[2][N], cache[2][N];

int dp(int i, int idx)
{
	if(idx > n)
		return 0;
	int &ans = cache[i][idx];
	if(ans != -1)
		return ans;
	ans = max(dp(i, idx + 1), a[i][idx] + dp(i ^ 1, idx + 1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 0; i <= 1; i++)
	{
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	int ans = max(dp(0, 1), dp(1, 1));
	cout << ans;
	return 0;
}