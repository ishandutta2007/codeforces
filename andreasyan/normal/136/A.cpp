#include <iostream>
using namespace std;
int a[102];
int main()
{
	int i, j, k, n, m;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> k;
		a[k] = i;
	}
	for (i = 1; i <= n; i++)
		cout << a[i]<<' ';
	cout << endl;
	return 0;
}