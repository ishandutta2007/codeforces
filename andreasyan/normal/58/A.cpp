#include <iostream>
using namespace std;
char a[102], b[10] = { 'h','e','l','l','o' };
int main()
{
	int i, j, k, n, m;
	cin >> a;
	n = strlen(a);
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == b[j])
			j++;
		if (j == 5)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}