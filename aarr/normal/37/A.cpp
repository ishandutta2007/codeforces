#include<iostream>

using namespace std;

int a[1005];
int main()
{
	int n, b = 0, c = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		a[x] ++;
	}
	for(int i = 0; i < 1001; i ++)
	{
		if(a[i] != 0)
		{
			b ++;
			if(a[i] > c)
			{
				c = a[i];
			}
		}
	}
	cout << c << " " << b;
	return 0;
}