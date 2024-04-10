#include <iostream>
#include <cstring>
using namespace std;

char a[500];
int b[2];
int n, k = 1, x, y, m;
char z;

int main()
{
	int i, j;
	while (1)
	{
		cin >> z;
		if (z == '+')
		{
			x++;
			a[k] = '+';
			k++;
		}
		if (z == '-')
		{
			y++;
			a[k] = '-';
			k++;
		}
		if (z == '=')
			break;
	}
	x++;
	a[0] = '+';
	cin >> n;
	if (x*n - y < n || x - y*n > n)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for (i = 0; i < k; i++)
	{
		z = 1;
		if (a[i] == '-')
			z = -1;
		if (z == 1)
			x--;
		else
			y--;
		for (j = 1; j <= n; j++)
		{
			if (m + j*z + x*n - y >= n && m + j*z + x - y*n <= n)
			{
				if (i == 0)
				{
					cout << j << ' ';
				}
				if (z == -1)
					cout << "- " << j << ' ';
				if (z == 1 && i != 0)
					cout << "+ " << j << ' ';
				m += j*z;
				break;
			}
		}
	}
	cout << "= " << n << endl;
//	system("pause");
	return 0;
}