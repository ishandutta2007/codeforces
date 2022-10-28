#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		int ans = 0;
		int val = 1e9;
		while(val > 0)
		{
			while(val <= x)
			{
				ans += val;
				x -= val;
				x += val / 10;
			}
			val /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}