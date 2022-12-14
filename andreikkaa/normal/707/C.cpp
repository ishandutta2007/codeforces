#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll x;
	cin >> x;
	
	if(x <= 2)
	{
		cout << - 1 << endl;
		return 0;
	}
	
	if(x == 4)
	{
		cout << "3 5" << endl;
		return 0;
	}
	
	if((x & (x - 1)) == 0)
	{
		ll n = (x - 4) / 4;
		ll m = n + 2;
		cout << 2 * m * n << " " << m * m + n * n << endl;
		return 0;
	}
	else
	{
		ll mul = 1;
		while(x % 2 == 0)
		{
			mul <<= 1;
			x >>= 1;
		}
		ll n = x / 2;
		ll m = n + 1;
		cout << mul * (2 * m * n) << " " << mul * (m * m + n * n) << endl;
		return 0;
	}
}