#include <iostream>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	if (n % 2 == 1)
		n++;
	if (m <= n / 2)
	{
		cout << m * 2 - 1 << endl;
	}
	else
	{
		cout << m - (n - m) << endl;
	}
	return 0;
}