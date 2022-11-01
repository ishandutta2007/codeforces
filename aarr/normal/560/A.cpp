#include<iostream>

using namespace std;

int a[1000000];
int main()
{
	int n;
	bool b = false;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			b = true;
		}
		else
		{
			for(int j = 1; j < 1000000 / x; j ++)
			{
				a[j * x] = 7;
			}
		}
	}
	if(b)
	{
		cout << -1;
	}
	else
	{
		cout << 1;
	}
	return 0;
}