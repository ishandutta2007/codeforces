#include <iostream>

using namespace std;

int evkd(int a, int b);

int main()
{
	int n, a, b;
	cin >> n;
	a = (n - 1) / 2;
	b = n - a;
	while (evkd(a, b) == 0)
	{
		--a;
		++b;
	}
	cout << a << " " << b;
	return 0;
}

int evkd(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a < b) b = b % a;
		else a = a % b;
	}
	if (a == 1 || b == 1) return 1;
	return 0;
}