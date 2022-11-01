#include<iostream>

using namespace std;

int main()
{
	long long n;
	long long x = -1, y = 10000000000, a = 0, b = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int m;
		cin >> m;
		if(m == x)
		{
			a ++;
		}
		if(m > x)
		{
			x = m;
			a = 1;
		}
		if(m == y)
		{
			b ++;
		}
		if(m < y)
		{
			y = m;
			b = 1;
		}
	}
	if(x == y)
	{
		cout << 0 << " " << a * (a - 1) / 2;
	}
	else
	{
		cout << x - y << " " << a * b;
	}
	return 0;
}