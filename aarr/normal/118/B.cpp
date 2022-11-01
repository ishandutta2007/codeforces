#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int j = 0; j < n * 2; j ++)
	{
		cout << " ";
	}
	cout << 0 << endl;
	for(int i = 1; i < n * 2; i ++)
	{
		int b = 0;
		for(int j = 0; j < n * 2 + 1; j ++)
		{
			if(j != 0)
			{
				cout << " ";
			}
			int a = abs(n - i) + abs(n - j);
			a = n - a;
			if(a == 0)
			{
				b ++;
			}
			if(b == 2)
			{
				cout << 0;
				break;
			}
			if(a < 0)
			{
				cout << " ";
			}
			else
			{
				cout << a;
			}
		}
		cout << endl;
	}
	for(int j = 0; j < n * 2; j ++)
	{
		cout << " ";
	}
	cout << 0;
	return 0;
}