#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for(int i = 1; i <= r; i *= 2)
	{
		int cur = i;
		while(cur <= r)
		{
			if(cur >= l)
				ans++;
			cur *= 3;
		}
	}
	cout << ans;
	return 0;
}