#include <iostream>

using namespace std;

int main()
{
	int n, m, i = 1;
	cin >> n;
	cin >> m;
	while(m >= i)
	{
		m -= i;
		i ++;
		if(i > n)
		{
			i = 1;
		}
	}
	cout << m;
	return 0;
}