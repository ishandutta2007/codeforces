#include <iostream>
using namespace std;

int main()
{
	int i,h=0, k, n, m=0,maxim=0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> k;
		if (k >= m)
			h++;
		else
			h = 1;
		if (h > maxim)
			maxim = h;
		m = k;
	}
	cout << maxim << endl;
	return 0;
}