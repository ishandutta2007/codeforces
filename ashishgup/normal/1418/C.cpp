#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];
int cache[N][2];

int dp(int idx, int player)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx][player];
	if(ans != -1)
		return ans;
	ans = 1e9;
	if(player == 0)
		ans = min(dp(idx + 1, 1), dp(idx + 2, 1));
	else
		ans = min(a[idx] + dp(idx + 1, 0), a[idx] + a[idx + 1] + dp(idx + 2, 0));
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
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cache[i][0] = cache[i][1] = -1;
		}
		int ans = dp(1, 1);
		cout << ans << endl;
	}
	return 0;
}