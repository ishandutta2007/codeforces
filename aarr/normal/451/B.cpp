#include <iostream>

using namespace std;

int a[100005];
int main()
{
	int n, b = 0, x = 1;
	bool c = true;
	cin >> n;
	int y = n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i < n; i ++)
	{
		if(a[i] < a[i - 1] && b == 0)
		{
			b ++;
			x = i;
		}
		if(b == 1 && a[i] > a[i - 1])
		{
			if(a[i] < a[x - 1])
			{
				c = false;
			}
			b ++;
			y = i;
		}
		if(a[i] < a[i - 1] && b == 2)
		{
			c = false;
		}
	}
	if(b == 0)
	{
		y = 1;
	}
	if(b == 1 && a[x - 2] > a[y - 1])
	{
		c = false;
	}
	if(c)
	{
		cout << "yes" << endl;
		cout << x << " " << y;
	}
	else
	{
		cout << "no";
	}
	return 0;
}