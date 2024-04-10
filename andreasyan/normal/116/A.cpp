#include <iostream>
using namespace std;

int main()
{
	int i, j, k, n, m=0,x,y,maxim=0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		m = m - x;
		m = m + y;
		if (m > maxim)
			maxim = m;
	}
	cout << maxim << endl;
	return 0;
}