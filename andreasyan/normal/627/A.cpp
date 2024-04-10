#include <iostream>
using namespace std;

long long i, k, s, x, n = 1, y;
bool funkc(long long y, long long x)
{
	while(y)
	{
		if (y % 2 == x % 2 && x % 2 == 1)
			return false;
		y = y / 2;
		x = x / 2;
	}
	return true;
}
int main()
{
	long long y;
	cin >> s >> x;
	if (s % 2 != x % 2)
	{
		cout << '0' << endl;
		return 0;
	}
	if (x > s)
	{
		cout << '0' << endl;
		return 0;
	}
	y = (s - x) / 2;
	if (!funkc(y, x))
	{
		cout << '0' << endl;
		return 0;
	}
	y = x;
	while (y)
	{
		k += y % 2;
		y = y / 2;
	}
	for (i = 0; i < k; i++)
		n = n * 2;
	if (x == s)
		n -= 2;
	cout << n << endl;
//	system("pause");
	return 0;
}