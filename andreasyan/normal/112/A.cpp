#include <iostream>
using namespace std;

char a[102], b[102];
int main()
{
	int i, j, k=0, n, m,k2=0;
	char e;
	cin >> a >> b;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (b[i] >= 'A' && b[i]<= 'Z')
		{
			e = b[i] - 'A' + 'a';
			b[i] = e;
		}
		if (a[i] >= 'A' && a[i]<= 'Z')
		{
			e = a[i] - 'A' + 'a';
			a[i] = e;
		}
		if (a[i] > b[i])
		{
			cout << '1' << endl;
			return 0;
		}
		if (a[i] < b[i])
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << '0' << endl;
	return 0;
}