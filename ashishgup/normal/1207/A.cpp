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
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ans = 0;
		for(int i = 0; i <= p; i++)
		{
			if(i * 2 > b)
				break;
			int cur = h * i;
			int left = b - 2 * i;
			int make = min(left / 2, f);
			cur += make * c;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}