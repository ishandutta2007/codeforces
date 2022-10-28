#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int r, b, k;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> r >> b >> k;
		int lcm = (r * b) / __gcd(r, b);
		int x = lcm / r - 1;
		int y = lcm / b - 1;
		int takeR = x / (y + 1) + (x % (y + 1) > 0);
		int takeB = y / (x + 1) + (y % (x + 1) > 0);
		if(takeR >= k || takeB >= k)
		{
			cout << "REBEL" << endl;
			continue;
		}
		cout << "OBEY" << endl;
	}
	return 0;
}