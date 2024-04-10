#include <iostream>
using namespace std;

bool parz(int x)
{
	if (x == 0)
		return false;
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	int i;
	for (i = 3; i*i <= x; i += 2)
		if (x%i == 0)
			return false;
	return true;
}
bool ban(int x, int y)
{
	if (parz(x) == false && parz(y) == false)
		return true;
	return false;
}
int main()
{
	int i, j, k, n, m;
	cin >> n;
	if (ban(n / 2, n - n / 2) == true)
	{
		cout << n / 2 << ' ' << n - n / 2 << endl;
		return 0;
	}
	for (i = 1; i < n / 2; i++)
	{
		if (ban(n / 2 + i, n - n / 2 - i) == true)
		{
			cout << n / 2 + i << ' ' << n - n / 2 - i << endl;
			return 0;
		}
		if (ban(n / 2 - i, n - n / 2 + i) == true)
		{
			cout << n / 2 - i << ' ' << n - n / 2 + i << endl;
			return 0;
		}
	}
	
	return 0;
}