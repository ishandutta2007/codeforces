#include <iostream>

using namespace std;

int a[105];
int b[105];
int c[105];
int d[105];
int main()
{
	int n, e = 0, f = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		if(x < 0)
		{
			a[e] = x;
			b[e] = y;
			e ++;
		}
		else
		{
			c[f] = x;
			d[f] = y;
			f ++;
		}
	}
	for(int i = 0; i < e; i ++)
	{
		for(int j = 1; j < e; j ++)
		{
			if(a[j] > a[j - 1])
			{
				swap(a[j], a[j - 1]);
				swap(b[j], b[j - 1]);
			}
		}
	}
	for(int i = 0; i < f; i ++)
	{
		for(int j = 1; j < f; j ++)
		{
			if(c[j] < c[j - 1])
			{
				swap(c[j], c[j - 1]);
				swap(d[j], d[j - 1]);
			}
		}
	}
	int s = 0;
	for(int i = 0; i < e && i <= f; i ++)
	{
		s += b[i];
	}
	for(int i = 0; i <= e && i < f; i ++)
	{
		s += d[i];
	}
	cout << s;
	return 0;
}