#include <iostream>
#include <map>
using namespace std;

long long n, m, k, a[500002], p[500002], c[500002];
int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] + a[i];
	}
	if (p[n] % 3 == 0)
	{
		k = p[n] / 3;
		for (i = 1; i <= n; i++)
		{
			c[i] = c[i - 1];
			if (p[i] == k)
				c[i]++;
		}
		for (i = 1; i < n; i++)
		{
			if (p[n] - p[i]==k)
				m+=c[i-1];
		}
	}
	cout << m << endl;
	return 0;
}