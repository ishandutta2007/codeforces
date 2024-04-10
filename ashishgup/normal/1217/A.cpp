#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int x = (b + c - a) / 2;
		if(2 * x <= b + c - a)
			x++;
		int ans = max(x, 0LL);
		ans = (c - ans + 1);
		ans = max(ans, 0LL);
		cout << ans << endl;
	}
	return 0;
}