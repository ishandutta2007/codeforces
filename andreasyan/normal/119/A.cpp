#include <iostream>
using namespace std;

int nbod(int x, int y)
{
	while (x !=0 && y!=0)
	{
		if (x >= y)
		{
			x = x%y;
			continue;
		}
		else
		{
			y = y%x;
		}
	}
	return x+y;
}
int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	while(1)
	{
		n = n - nbod(a, n);
		if (n < 0)
		{
			cout << '1' << endl;
			return 0;
		}
		n = n - nbod(b, n);
		if (n < 0)
		{
			cout << '0' << endl;
			return 0;
		}
	}
	return 0;
}