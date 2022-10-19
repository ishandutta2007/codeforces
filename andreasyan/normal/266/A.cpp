#include <iostream>
using namespace std;

char a[55];
int main()
{
	int i, j, k=0, n, m=0;
	cin >> n;
	cin >> a;
	for (i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
			m++;
		else
		{
			k += m;
			m = 0;
		}
	}
	k += m;
	cout << k << endl;
	return 0;
}