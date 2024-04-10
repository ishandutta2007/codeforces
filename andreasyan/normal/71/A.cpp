#include <iostream>
using namespace std;

char a[102];
int main()
{
	int i, j, n, m, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		m = strlen(a);
		if (m > 10)
			cout << a[0] << m - 2 << a[m - 1]<<endl;
		else
			cout << a<<endl;
	}
	return 0;
}