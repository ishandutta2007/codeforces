#include <iostream>
using namespace std;
int a[6];
bool ban(int x)
{
	int j=0,i,k;
	while (x!=0)
	{
		a[j] = x % 10;
		x = x / 10;
		j++;
	}
	for (i = 0; i < j; i++)
	{
		for (k = 0; k < j; k++)
		{
			if (a[i] == a[k] && i != k)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int i, j, k, n, m;
	cin >> n;
	for (i = n + 1; i < 10000; i++)
	{
		if (ban(i) == true)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}