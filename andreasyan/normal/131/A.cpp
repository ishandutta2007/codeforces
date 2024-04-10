#include <iostream>
using namespace std;
char a[102];
int main()
{
	int i, j, k, n, m=0;
	char e;
	cin >> a;
	n = strlen(a);
	for (i = 1; i < n; i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			m++;
	if (m != n - 1)
	{
		cout << a << endl;
		return 0;
	}
	if (a[0] >= 'A' && a[0] <= 'Z')
	{
		e = a[0] - 'A' + 'a';
		cout << e;
	}
	else
	{
		e = a[0] - 'a' + 'A';
		cout << e;
	}
	for (i = 1; i < n; i++)
	{
		e = a[i] - 'A' + 'a';
		cout << e;
	}
	cout << endl;
	return 0;
}