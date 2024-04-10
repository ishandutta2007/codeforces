#include <iostream>
using namespace std;

bool ans(int a,int b)
{
	int x = b / 2;
	int y = 0;
	int p = -1;
	while (1)
	{
		if (x + y == p)
		{
			return 0;
		}
		p = x + y;
		if (2 * (b - 2 * (x + y)) == a - (x + y) && b >= 2 * (x + y))
		{
			return 1;
		}
		else if (2 * (b - 2 * (x + y)) < a - (x + y))
		{
			x = x / 2;
		}
		else if (2 * (b - 2 * (x + y)) > a - (x + y))
		{
			y += x;
			x = x / 2 + x % 2;
		}
	}
}

int main()
{
	int t;
	int a[100], b[100];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < t; i++)
	{
		cout << (ans(a[i], b[i]) ? "YES" : "NO") << endl;
	}
}