#include <iostream>

using namespace std;

int main()
{
	long long n, k;
	cin >> n;
	cin >> k;
	int s = 0, x = 0;
	for(int i = 1; 1ll * i * i <= n; i ++)
	{
		if(n % i == 0)
		{
			s ++;
		}
		if(s == k)
		{
			cout << i;
			return 0;
		}
		x = i;
	}
	if(1ll * x * x == n)
	{
		x --;
	}
	//cout << endl << x;
	for(int i = x; i > 0; i --)
	{
		if(n % i == 0)
		{
			s ++;
		}
		if(s == k)
		{
			cout << n / i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}