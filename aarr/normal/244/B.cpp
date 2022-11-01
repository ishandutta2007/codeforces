#include <iostream>

using namespace std;

long long n;
void next(long long i, long long x, long long y)
{
	if((n % i) / (i / 10) == x)
	{
		n = n - (i / 10) * (x - y);
	}
	else
	{
		if((n % i) / (i / 10) == y)
		{
			while((n % i) / (i / 10) == y)
			{
				n = n - (i / 10) * (y - x);
				i *= 10;
			}
			next(i, x, y);
		}
		else
		{
			n += x * (i / 10);
		}
	}
}
void nxt(long long i, long long x)
{
	//cout << (n % i) / (i / 10) << endl;
	if((n % i) / (i / 10) == x)
	{
		nxt(i * 10, x);
	}
	else
	{
		n += x * (i / 10);
	}
}
void nexxt(long long i, long long x)
{
	if((n % i) / (i / 10) == x)
	{
		n = n - (i / 10) * x;
		nexxt(i * 10, x);
	}
	else
	{
		n += (i / 10) * x;
	}
}
int main()
{
	long long m, ans = 0;
	cin >> m;
	for(long long i = 1; i < 10; i ++)
	{
		for(long long j = i + 1; j < 10; j ++)
		{
			n = i;
			while(n <= m)
			{
				//cout <<i << " " << j << " " << n << endl;
				//cout << n << endl;
				next(10, i, j);
				ans ++;
			}
			//cout << i << endl;
		}
	}
	for(long long i = 1; i < 10; i ++)
	{
		n = i;
		while(n <= m)
		{
			//cout << n << endl;
			nxt(10, i);
			ans -= 8;
		}
	}
	for(long long i = 1; i < 10; i ++)
	{
		n = i;
		while(n <= m)
		{
			//cout << n << endl;
			nexxt(10, i);
			ans ++;
		}
	}
	cout << ans;
	return 0;
}