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
		int cost = 1;
		for(int i = 3; i <= n; i += 2)
		{
			ans += cost * (i * i - (i - 2) * (i - 2));
			cost++;
		}
		cout << ans << endl;
	}
	return 0;
}