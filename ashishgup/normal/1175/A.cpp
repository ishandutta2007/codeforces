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
		int n, k;
		cin >> n >> k;
		int ans = 0;
		while(n > 0)
		{
			if(n % k > 0)
			{
				ans += n % k;
				n -= (n % k);
			}
			if(n > 0 && n % k == 0)
			{
				ans++;
				n /= k;
			}
		}
		cout << ans << endl;
	}
	return 0;
}