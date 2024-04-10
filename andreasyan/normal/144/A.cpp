#include <iostream>
using namespace std;

int a[102];
int main()
{
	int i, j, k, n, m,minx,maxx,maxim,minim;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	maxim = 0;
	for (i = 1; i <= n; i++)
	{
		if (a[i] > maxim)
		{
			maxim = a[i];
			maxx = i;
		}
	}
	minim = 99999;
	for (i = 1; i <= n; i++)
	{
		if (a[i] <= minim)
		{
			minx = i;
			minim = a[i];
		}
	}
	if (maxx < minx)
		cout << maxx + n - minx - 1 << endl;
	else
		cout << maxx + n - minx - 2 << endl;
	return 0;
}