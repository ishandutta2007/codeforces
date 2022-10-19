#include <iostream>
using namespace std;

char a[102];
int main()
{
	int i, j, k=0, n, m=0;
	cin >> a;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (a[i] == '0')
		{
			m++;
			k = 0;
		}
		else
		{
			k++;
			m = 0;
		}
		if (k == 7 || m==7)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}