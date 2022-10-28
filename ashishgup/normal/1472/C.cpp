//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
bool vis[N];
int a[N], cache[N];

int dp(int idx)
{
	if(idx > n)
		return 0;
	if(vis[idx])
		return cache[idx];
	vis[idx] = 1;
	cache[idx] = a[idx] + dp(idx + a[idx]);
	return cache[idx];
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
			vis[i] = 0;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, dp(i));
		cout << ans << endl;
	}
	return 0;
}