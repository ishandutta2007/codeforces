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
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int mx = max({a, b, c});
		int reqd = 3 * mx - a - b - c;
		if(n < reqd || (reqd - n) % 3)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}