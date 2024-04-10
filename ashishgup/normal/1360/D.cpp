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
		int ans = 1e9;
		for(int i = 1; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				if(i <= k)
					ans = min(ans, n / i);
				if(n / i <= k)
					ans = min(ans, i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}