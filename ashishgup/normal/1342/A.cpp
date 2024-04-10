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
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		b = min(b, 2 * a);
		int ans = min(x, y) * b;
		ans += (max(x, y) - min(x, y)) * a;
		cout << ans << endl;
	}
	return 0;
}