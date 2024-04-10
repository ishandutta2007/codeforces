#include <iostream>
using namespace std;

int main()
{
	int k=0,n, m,p=0, mn;
	cin >> n >> m;
	while (1)
	{
		k += n;
		mn = (n + p) % m;
		n = (n + p) / m;
		p = mn;
		if (n == 0)
			break;
	}
	cout << k << endl;
	return 0;
}