#include <iostream>

using namespace std;

int main()
{
	int n, k, i, s = 0;
	cin >> n >> k;
	int* a = new int[n];
	for (i = 0; i < n; ++i)
	{
		cin >> a[i];
		s += a[i];
	}
	int rez = (k*n - s) * 2 - n;
	if (rez < 0) rez = 0;
	cout << rez;
	return 0;
}