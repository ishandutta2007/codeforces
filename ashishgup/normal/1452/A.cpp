#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int x, y;
		cin >> x >> y;
		int ans = 2 * min(x, y) + (max(x, y) > min(x, y)) + (max(0LL, max(x, y) - min(x, y) - 1)) * 2;
		cout << ans << endl;
	}
	return 0;
}