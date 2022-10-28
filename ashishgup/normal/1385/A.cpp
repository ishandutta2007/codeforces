//Random order + Quit = Because of lockout against Shashwat

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
		int x, y, z;
		cin >> x >> y >> z;
		int a = 1e9, b = 1e9, c = 1e9;
		a = min(x, y);
		b = min(x, z);
		c = min(y, z);
		if(max(a, b) == x && max(a, c) == y && max(b, c) == z)
		{
			cout << "YES" << endl;
			cout << a << " " << b <<  " " << c << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}