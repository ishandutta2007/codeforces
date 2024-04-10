#include <iostream>
#include <cmath>
using namespace std;
int a[6][6];
int main()
{
	int i, j, k, n, m;
	for (i = 1; i <= 5; i++)
		for (j = 1; j <= 5; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				n = i; m = j;
			}
		}
	cout << abs(3 - n) + abs(3 - m)<<endl;
	return 0;
}