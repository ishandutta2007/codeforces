#include <iostream>
using namespace std;

char a[102], b[102];
int main()
{
	int n, i, j;
	cin >> a >> b;
	n = strlen(a);
	for (i = 0, j = n - 1; i < n, j >= 0; i++, j--)
	{
		if (a[i] != b[j])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}