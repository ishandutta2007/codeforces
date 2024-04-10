#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *x = new int[n];
	int i;
	for (i = 0; i < n; ++i)
	{
		cin >> a[i];
		x[i] = 0;
	}
	int *b = new int[n + 1];
	b[0] = 1;
	int t = n, j;
	for (i = 1; i <= n; ++i)
	{
		x[a[i - 1] - 1] = 1;
		if (a[i - 1] == n) --t;
		if (t < n)
		{
			j = t - 1;
			while (x[j] == 1)
				--j;
			t = j + 1;

		}
		b[i] = i + 1 - (n - t);
		if (b[i] == 0) ++b[i];
	}
	for (i = 0; i <= n; ++i)
		cout << b[i] << " ";
	return 0;
}