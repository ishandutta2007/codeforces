#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n, x, y, a[1001];
int main()
{
	cin >> n >> x >> y;
	int pqx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= x)
			pqx++;
	}
	if (y < x)
	{
		cout << n;
		return 0;
	}
	if (pqx % 2 == 0)
	{
		cout << pqx / 2;
	}
	else
		cout << pqx / 2 + 1;
	return 0;
}