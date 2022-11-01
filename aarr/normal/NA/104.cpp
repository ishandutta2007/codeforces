#include <iostream>

using namespace std;

int a[100005];
int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	int x = n - k - 1;
	for(int i = 0; i <= k; i ++)
	{
		if(i % 2 == 1)
		{
			a[i + x] = i / 2 + 1;
		}
		else
		{
			a[i + x] = k - i / 2 + 1;
		}
	}
	for(int i = 0; i < x; i ++)
	{
		a[i] = n - i;
	}
	for(int i = 0; i < n; i ++)
	{
		cout << a[i] << " ";
	}
	return 0;
}