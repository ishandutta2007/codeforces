#include <iostream>
using namespace std;

int main()
{
	int i, j, k=0, n, m;
	cin >> n >> m;
	if (n >= 2)
		k += n / 2 * m;
	if (n % 2 == 1)
		k += m / 2;
	cout << k << endl;
	return 0;
}