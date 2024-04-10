#include <iostream>
using namespace std;

int n, m, k, a[100];
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	if (a[n - 1] == 15)
	{
		cout << "DOWN" << endl;
		return 0;
	}
	if (a[n - 1] == 0)
	{
		cout << "UP" << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << "-1" << endl;
		return 0;
	}
	if (a[n - 1] > a[n - 2])
		cout << "UP" << endl;
	else
		cout << "DOWN" << endl;
//	system("pouse");
	return 0;
}