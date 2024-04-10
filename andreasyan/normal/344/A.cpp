#include <iostream>
using namespace std;

int a[100002];
int main()
{
	int i, k=0, n;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
			k++;
	}
	cout << k + 1 << endl;
	return 0;
}