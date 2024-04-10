#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,ans1,ans, m, a[1000000];
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		m += a[i];
	}
	int t = m / n;
	int z = m%n;
	for (i = 0; i < n; i++)
	{
		if (a[i] > t)
		{
			ans += a[i] - t;
			if (z)
			{
				z--;
				ans--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}