#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		if(n <= 6)
		{
			cout << 15 << endl;
			continue;
		}
		int take = n / 6;
		ans += 15 * take;
		n -= take * 6;
		if(n >= 5)
			ans += 15;
		else if(n >= 3)
			ans += 10;
		else if(n >= 1)
			ans += 5;
		cout << ans << endl;
	}
	return 0;
}