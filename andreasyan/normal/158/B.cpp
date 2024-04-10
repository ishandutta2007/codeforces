#include <iostream>
using namespace std;

int a[5];
int main()
{
	int i, j, k=0, n, m;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> m;
		a[m]++;
	}
	k += a[4];
	k += a[3];
	a[1] = a[1] - a[3];
	if (a[1] < 0)
		a[1] = 0;
	k += a[2] / 2;
	if (a[2] % 2 == 1)
		a[1] += 2;
	if (a[1] > 0)
		k += a[1] / 4 + !!(a[1] % 4);
	cout << k << endl;
	return 0;
}