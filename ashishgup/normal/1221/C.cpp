#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	while(q--)
	{
		int c, m, x;
		cin >> c >> m >> x;
		int ans = min({c, m, (c + m + x) / 3});
		cout << ans << endl;
	}
	return 0;
}