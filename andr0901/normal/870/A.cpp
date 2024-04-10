#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n], b[k];
	bool x = 0, y = 0;
	int z = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < k; j++)
	{
		cin >> b[j];
	}
	while ((x + y) < 2)
	{
		x = 0;
		y = 0;
	    int c = z;
		while (c != 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] == c % 10) x = 1;
			}
			for (int j = 0; j < k; j++)
			{
				if (b[j] == c % 10) y = 1;
			}
			c = c / 10;
		}
		
		z++;
	}
	cout << z -1;
    return 0;
}