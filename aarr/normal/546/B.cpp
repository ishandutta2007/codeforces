#include <iostream>

using namespace std;

int a[6005];
int main()
{
	int n, m = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		a[x] ++;
	}
	if(n == 50)
	{
		for(int i = 0; i < 50; i ++)
		{
			cerr << a[i] << endl;
		}
	}
	for(int i = 0; i <= n; i ++)
	{
		if(a[i] > 1)
		{
			for(int j = 0; j < a[i] - 1; j ++)
			{
				int k = i;
				while(a[k] != 0)
				{
					k ++;
				}
				a[k] = 1;
				m += k - i;
			}
		}
		a[i] = 1;
	}
	cout << m;
	return 0;
}