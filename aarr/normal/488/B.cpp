#include <iostream>

#include <algorithm>

using namespace std;

int a[5];
int b[5];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(n == 0)
	{
		cout << "YES" << endl << 1 << endl << 1 << endl << 3 << endl << 3;
	}
	if(n == 1)
	{
		cout << "YES" << endl << a[1] << endl << a[1] * 3 << endl << a[1] * 3;
	}
	if(n == 4)
	{
		if(a[1] * 3 == a[4] && a[2] + a[3] == a[1] * 4)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	if(n == 3)
	{
		bool c = 1;
		for(int i = 1; i <= 1500; i ++)
		{
			b[1] = a[1], b[2] = a[2], b[3] = a[3], b[4] = i;
			sort(b + 1, b + 5);
			if(c && b[1] * 3 == b[4] && b[2] + b[3] == b[1] * 4)
			{
				cout << "YES" << endl << i;
				c = 0;
			}
		}
		if(c)
		{
			cout << "NO";
		}
	}
	if(n == 2)
	{
		bool c = 1;
		for(int i = 1; i <= 1500; i ++)
		{
			for(int j = 1; j <= 1500; j ++)
			{
				b[1] = a[1], b[2] = a[2], b[3] = j, b[4] = i;
				sort(b + 1, b + 5);
				if(c && b[1] * 3 == b[4] && b[2] + b[3] == b[1] * 4)
				{
					cout << "YES" << endl << i << endl << j;
					c = 0;
				}
			}
		}
		if(c)
		{
			cout << "NO";
		}
	}
	return 0;
}