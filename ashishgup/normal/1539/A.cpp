#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n, x, t;
		cin >> n >> x >> t;
		int lim = t / x;
		int take = min(n - 1, lim);
		int ans = take * (take + 1) / 2 + (n - 1 - take) * lim;
		cout << ans << endl;
	}
	return 0;
}