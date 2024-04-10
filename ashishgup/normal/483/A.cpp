#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int l, r;
	cin >> l >> r;
	for(int a = l; a <= r; a++)
	{
		for(int b = a + 1; b <= r; b++)
		{
			for(int c = b + 1; c <= r; c++)
			{
				if(__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) > 1)
				{
					cout << a << " " << b << " " << c;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}