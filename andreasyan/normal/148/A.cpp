#include <iostream>
using namespace std;
int a[5];
int main()
{
	int i, j, k=0,n, m;
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			if (i%a[j] == 0)
			{
				k++;
				break;
			}
		}
	}
	cout << k << endl;
	return 0;
}