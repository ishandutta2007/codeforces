#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int x, y, k;
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x >> y >> k;
		int ans = (k * y + k - 1 + x - 2) / (x - 1) + k;
		cout << ans << endl;
	}
	return 0;
}