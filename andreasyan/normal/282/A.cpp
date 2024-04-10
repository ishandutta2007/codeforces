#include <iostream>
using namespace std;

int main()
{
	int i, j, n,m=0;
	char x, y, z;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		if (y == '+')
			m++;
		if (y == '-')
			m--;
	}
	cout << m<<endl;
	return 0;
}