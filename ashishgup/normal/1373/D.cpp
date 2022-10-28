//Need to leave around 9:30

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], cache[N][3][2];

int dp(int idx, int cur, int st)
{
	if(idx >= n)
	{
		if(cur == 1)
			return -1e18;
		return 0;
	}
	int &ans = cache[idx][cur][st];
	if(ans != -1)
		return ans;
	if(cur == 0)
	{
		ans = (idx % 2 == 0) * a[idx] + dp(idx + 1, cur, st); //continue
		ans = max(ans, (idx % 2) * a[idx] + dp(idx + 1, 1, idx % 2));
	}
	else if(cur == 1)
	{
		ans = (idx % 2) * a[idx] + dp(idx + 1, cur, st); //continue
		if(st != (idx % 2))
			ans = max(ans, (idx % 2) * a[idx] + dp(idx + 1, 2, idx % 2));
	}
	else
		ans = (idx % 2 == 0) * a[idx] + dp(idx + 1, cur, st); //continue
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= 2; j++)
				for(int k = 0; k <= 1; k++)
					cache[i][j][k] = -1;
		int ans = dp(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}