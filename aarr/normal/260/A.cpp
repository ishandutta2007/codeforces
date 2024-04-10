#include <iostream>

using namespace std;

int main()
{
	string a;
	int b, n, c = 0;
	cin >> a;
	cin >> b;
	cin >> n;
	for(int i = 0; i < a.size(); i ++)
	{
		c = c * 10;
		c += (a[i] - '0');
	}
	int e = 0;
	for(int i = 0; i < n; i ++)
	{
		c = c % b;
		c *= 10;
		c = c % b;
		int d = 0;
		for(int j = 0; j < 10; j ++)
		{
			if((c + j) % b == 0)
			{
				a += (j + '0');
				d = 1;
				c = 0;
				break;
			}
		}
		if(d == 0)
		{
			e = -1;
			cout << -1;
			break;
		}
	}
	if(e != -1)
	{
		cout << a;
	}
	return 0;
}