#include <iostream>
using namespace std;

int a[30003];
int main()
{
	int i, j, k, n, m;
	cin >> n >> k;
	for (i = 1; i <= n-1; i++)
	{
		cin >> a[i];
	}
	i = 1;
	while (1)
	{
		i = a[i] + i;
		if (i == k)
		{
			cout << "YES" << endl;
			return 0;
		}
		if (i > k)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	return 0;
}