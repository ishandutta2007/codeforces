#include <iostream>
#include <algorithm>
using namespace std;

int a[60];
int main()
{
	int n, m, i, j, k,minim=9999999;
	cin >> m >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (i = 0; i <= n-m; i++)
	{
		k = a[i + m-1] - a[i];
		if (k < minim)
			minim = k;
	}
	cout << minim << endl;
	return 0;
}