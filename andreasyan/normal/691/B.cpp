#include <iostream>
#include <cstring>
using namespace std;

char a[1002];
int main()
{
	int i, j, k;
	int n;
	cin >> a;
	n = strlen(a);
	for (i = 0, j = n - 1; i < n, j >= 0; ++i, --j)
	{
		if (a[i] == 'A' && a[j] == 'A')continue;
		if (a[i] == 'b' && a[j] == 'd')continue;
		if (a[i] == 'd' && a[j] == 'b')continue;
		if (a[i] == 'H' && a[j] == 'H')continue;
		if (a[i] == 'I' && a[j] == 'I')continue;
		if (a[i] == 'M' && a[j] == 'M')continue;
		if (a[i] == 'O' && a[j] == 'O')continue;
		if (a[i] == 'o' && a[j] == 'o')continue;
		if (a[i] == 'p' && a[j] == 'q')continue;
		if (a[i] == 'q' && a[j] == 'p')continue;
		if (a[i] == 'T' && a[j] == 'T')continue;
		if (a[i] == 'U' && a[j] == 'U')continue;
		if (a[i] == 'V' && a[j] == 'V')continue;
		if (a[i] == 'v' && a[j] == 'v')continue;
		if (a[i] == 'W' && a[j] == 'W')continue;
		if (a[i] == 'w' && a[j] == 'w')continue;
		if (a[i] == 'X' && a[j] == 'X')continue;
		if (a[i] == 'x' && a[j] == 'x')continue;
		if (a[i] == 'Y' && a[j] == 'Y')continue;
		cout << "NIE" << endl;
		return 0;
	}
	cout << "TAK" << endl;
	return 0;
}