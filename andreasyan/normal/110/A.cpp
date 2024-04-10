#include <iostream>
using namespace std;

char a[20];
int main()
{
	int i, j, k = 0, n, m;
	cin >> a;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (a[i] == '4' || a[i] == '7')
			k++;
	}
	if ((k == 4 || k ==7) && k != 0)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}