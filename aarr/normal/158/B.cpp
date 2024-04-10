#include <iostream>

using namespace std;

int a[5];
int main()
{
	int n, c = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int b;
		cin >> b;
		a[b - 1] += 1;
	}
	c += a[3];
	c += a[2];
	a[0] = max(0, a[0] - a[2]);
	if((a[0] + a[1] * 2) % 4 == 0)
	{
		c += (a[0] + a[1] * 2) / 4;
	}
	else
	{
		c += (a[0] + a[1] * 2) / 4 + 1;
	}
	cout << c;
	return 0;
}