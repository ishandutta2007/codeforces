#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		int ans = 0;
		while(x % 5 == 0)
		{
			x = 4 * x / 5;
			ans++;
		}
		while(x % 3 == 0)
		{
			x = 2 * x / 3;
			ans++;
		}
		while(x % 2 == 0)
		{
			x /= 2;
			ans++;
		}
		if(x != 1)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}