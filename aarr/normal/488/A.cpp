#include <iostream>

using namespace std;

int chk(int a)
{
	if(a < 0)
	{
		a = -a;
	}
	while(a >= 1)
	{
		if(a % 10 == 8)
		return 1;
		a = a / 10;
	}
	return 0;
}
int main()
{
	long long n;
	cin >> n;
	int b = 100;
	for(int i = 20; i > 0; i --)
	{
		if(chk(n + i) == 1)
		{
			b = i;
		}
	}
	cout << b;
	return 0;
}