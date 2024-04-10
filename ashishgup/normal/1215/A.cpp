#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int ans = 0, mn = 1e9;
	for(int i = 0; i <= a1; i++)
	{
		for(int j = 0; j <= a2; j++)
		{
			int reqd = i * k1 + j * k2;
			if(reqd <= n)
				ans = max(ans, i + j);
		}
	}
	for(int i = 0; i <= a1; i++)
	{
		for(int j = 0; j <= a2; j++)
		{
			int reqd = i * k1 + j * k2 + (a1 - i) * (k1 - 1) + (a2 - j) * (k2 - 1);
			if(reqd >= n)
				mn = min(mn, i + j);
		}
	}
	cout << mn << " " << ans;
	return 0;
}