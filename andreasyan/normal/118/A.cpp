#include <iostream>
using namespace std;

char a[102];
int main()
{
	int i, j, k, n, m;
	cin >> a;
	char b;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (a[i] != 'A' && a[i] != 'O' && a[i] != 'Y' && a[i] != 'E' && a[i] != 'U' && a[i] != 'I' && a[i] != 'a' && a[i] != 'o' && a[i] != 'y' && a[i] != 'e' && a[i] != 'u' && a[i] != 'i' && a[i] >= 'A' && a[i] <= 'Z')
		{
			b = a[i] - 'A' + 'a';
			cout << '.' << b;
		}
		if (a[i] != 'A' && a[i] != 'O' && a[i] != 'Y' && a[i] != 'E' && a[i] != 'U' && a[i] != 'I' && a[i] != 'a' && a[i] != 'o' && a[i] != 'y' && a[i] != 'e' && a[i] != 'u' && a[i] != 'i' && a[i] >= 'a' && a[i] <= 'z')
			cout << '.' << a[i];
	}
	cout << endl;
	return 0;
}