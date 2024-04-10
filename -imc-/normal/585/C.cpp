#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y)
{
	while (x && y)
	{
		if (x > y)
			x %= y;
		else
			y %= x;
	}
	
	return x + y;
}

int main()
{
	ll x, y;
	cin >> x >> y;
	
	if (gcd(x, y) != 1)
	{
		printf("Impossible\n");
		return 0;
	}
	
	string answer = "";
	
	while (x != 1 || y != 1)
	{
		//printf("%lld %lld\n", x, y);
		if (x > y)
		{
			ll d = x / y;
			if (x % y == 0) d--;
			x -= d * y;
			
			cout << d << "A";
		}
		else
		{
			ll d = y / x;
			if (y % x == 0) d--;
			y -= d * x;
			
			cout << d << "B";
		}
	}
	
	cout << endl;
	
	return 0;
}