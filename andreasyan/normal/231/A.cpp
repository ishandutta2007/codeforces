#include <iostream>
using namespace std;

int main()
{
	int i, j, k=0, n, m,x,y,z;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		m = 0;
		cin >> x >> y >> z;
		if (x == 1)
			m++;
		if (y == 1)
			m++;
		if (z == 1)
			m++;
		if (m > 1)
			k++;
	}
	cout << k << endl;
	return 0;
}