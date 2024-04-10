#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;
 
int n, q;
int a[N];
int cache[N][2];

int dp(int idx, int flag)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx][flag];
	if(ans != -1)
		return ans;
	ans = dp(idx + 1, flag);
	if(!flag)
		ans = max(ans, a[idx] + dp(idx + 1, flag ^ 1));
	else
		ans = max(ans, -a[idx] + dp(idx + 1, flag ^ 1));
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cache[i][0] = cache[i][1] = -1;
		}
		int ans = dp(1, 0);
		cout << ans << endl;
	}
	return 0;
}