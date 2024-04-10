#include <iostream>
using namespace std;

char a[222];
int main()
{
	int i, n, m;
	cin >> a;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (a[i] == 'W' && a[i + 1] == 'U' && a[i + 2] == 'B')
		{
			i += 2;
			cout << ' ';
		}
		else
		{
			cout << a[i];
		}
	}
	cout << endl;
	return 0;
}