#include <iostream>
#include <string>
#include <cstring>
#include <string>
using namespace std;

int n, m;
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> k;
		m += k;
	}
	if (n == 1 && m==1)
	{
		cout << "YES" << endl;
		return 0;
	}
	if (n == 1 && m == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (m == n - 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}