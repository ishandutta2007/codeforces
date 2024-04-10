#include <iostream>

using namespace std;

int a[105];
int main()
{
	int n, s = 0, x = 0, y = 0, z = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	a[n + 1] = 0;
	a[0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i] == 0)
		{
			s ++;
			a[i] = 0;
			//cout << i << " " << a[i] << endl;
		}
		if(a[i] == 1)
		{
			if(a[i - 1] == 1)
			{
				s ++;
				a[i] = 0;
			}
		}
		if(a[i] == 2)
		{
			if(a[i - 1] == 2)
			{
				s ++;
				a[i] = 0;
				//cout << i << " " << a[i] << endl;
			}
		}
		if(a[i] == 3)
		{
			if(a[i - 1] == 1)
			{
				a[i] = 2;
			}
			if(a[i - 1] == 2)
			{
				a[i] = 1;
			}
			if(a[i - 1] == 0)
			{
				int x = 1;
				if(a[x + i] == 3)
				{
					x ++;
				}
				if(a[x + 1] == 0)
				{
					a[i] = 1;
				}
				if(x % 2 == 1)
				{
					if(a[x + i] == 1)
					{
						a[i] = 2;
					}
					else
					{
						a[i] = 1;
					}
				}
				else
				{
					a[i] = a[x + i];
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		//if(n != 100)
			//cout << b[i] << " ";
	}
	cout << endl;
	cout << s;
	return 0;
}