#include <iostream>
using namespace std;

long long n, m, k;
int main()
{
	long long i=0;
	cin >> n >> k;
	long long nn = n;
	if (k > n / 2)
		k = n / 2;
	while (i < k)
	{
		m = m + 1 + 2 * (nn - 2);
		nn = nn - 2;
		i++;
	}
	cout << m << endl;
	return 0;
}