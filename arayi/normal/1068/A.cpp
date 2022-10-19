#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long int n, m, l, k;
	cin >> n >> m >> k >> l;
	long long int a = k + l;
	if ((a) % m == 0 && a <= n)
	{
		cout << (a) / m;
		return 0;
	}
	else if (((a / m) + 1)*m <= n)
	{
		cout << a / m + 1;
		return 0;
	}
	cout << -1;
	return 0;
}