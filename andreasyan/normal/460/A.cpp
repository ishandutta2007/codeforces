#include <iostream>
using namespace std;

int main()
{
	int i, j, k=0, n, m;
	cin >> n >> m;
	while (1)
	{
		k++;
		n--;
		if (k % m == 0)
			n++;
		if (n == 0)
			break;
	}
	cout << k << endl;
	return 0;
}