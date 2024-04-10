#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b;
	cin >> a >> b;
	
	if (a < b)
	{
		cout << -1 << endl;
		return 0;
	}
	
	if (a == b)
	{
		cout << a << endl;
		return 0;
	}
	
	// x - y = 0
	// x + y = a + b
	
	ll n = (a + b) / (2 * b);
	
	long double t = (a + b) * 0.5 / n;
	cout << fixed << setprecision(12) << t << endl;
	
	return 0;
}