#include <iostream>
using namespace std;
int main()
{
	int i, j, k=0, n, m, x, y;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (y - x >= 2)
			k++;
	}
	cout << k << endl;
	return 0;
}