#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main()
{
	int i, j, k=0, n, m=0,t=0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		m += a[i];
	}
	sort(a, a + n);
	for (i = n - 1; i >= 0; i--)
	{
		k += a[i];
		m = m - a[i];
		t++;
		if (k > m)
		{
			cout << t << endl;
			return 0;
		}
	}
	return 0;
}