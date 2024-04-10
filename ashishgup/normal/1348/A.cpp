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
		int n;
		cin >> n;
		int ans = 0;
		for(int i = n; i >= 1; i--)
		{
			if(i == n || i <= n / 2 - 1)
				ans += (1LL << i);
			else 
				ans -= (1LL << i);
		}
		cout << ans << endl;
	}
	return 0;
}