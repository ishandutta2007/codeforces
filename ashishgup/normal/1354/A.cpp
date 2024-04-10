#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int a, b, c, d;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c >> d;
		a -= b;
		if(a <= 0)
		{
			cout << b << endl;
			continue;
		}
		if(d >= c)
			cout << -1 << endl;
		else
		{
			int rest = c - d;
			int ans = b + ((a + rest - 1) / rest) * c;
			cout << ans << endl;
		}
	}
	return 0;
}