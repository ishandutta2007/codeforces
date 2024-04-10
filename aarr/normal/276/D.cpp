#include <iostream>

using namespace std;

int slog2(long long a)
{
	int b = 0;
	if(a == 1 || a == 2)
	{
		b ++;
	}
	bool c = true;
	while(a > 1)
	{
		if(a % 2 == 1)
		{
			c = false;
		}
		a /= 2;
		b ++;
	}
	if(c == false)
	{
		b ++;
	}
	return b;	
}
long long pow2(long long a)
{
	long long b = 1;
	for(int i = 0; i < a; i ++)
	{
		b *= 2;
	}
	return b;
}
int main()
{
	long long l, r;
	cin >> l;
	cin >> r;
	long long x = l ^ r, y = slog2(x), z = pow2(y) - 1;
	cout << z;
	return 0;
}