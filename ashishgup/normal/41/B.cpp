#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, b;
int a[N];
 
int32_t main()
{
	IOS;
	cin >> n >> b;
	int ans = b, mn = 2e9;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mn = min(mn, a[i]);
		int cur = b / mn;
		int val = b - cur * mn + cur * a[i];
		ans = max(ans, val); 
	}
	cout << ans;
	return 0;
}