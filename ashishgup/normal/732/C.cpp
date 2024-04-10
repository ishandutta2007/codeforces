#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int ans = 3e18;
int a[3];
 
int32_t main()
{
	IOS;
	int tot = 0;
	for(int i = 0; i < 3; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	for(int i = 0; i < 3; i++)
	{
		int mx = max({a[i], a[(i + 1) % 3], a[(i + 2) % 3]});
		int cur = mx * 3 - tot;
		ans = min(ans, cur);
		mx = max({a[i] - 1, a[(i + 1) % 3], a[(i + 2) % 3]});
		cur = mx * 3 - tot + 1;
		ans = min(ans, cur);
		mx = max({a[i] - 1, a[(i + 1) % 3] - 1, a[(i + 2) % 3]});
		cur = mx * 3 - tot + 2;
		ans = min(ans, cur);
	}
	cout << ans;
	return 0;
}