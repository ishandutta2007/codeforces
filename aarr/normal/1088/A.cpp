#include <iostream>

using namespace std;

int main()
{
	int x;
	cin >> x;
	if(x < 2)
	{
		cout << -1;
	}
	else
	{
		if(x % 2 == 1)
		{
			x --;
		}
		cout << x << " " << 2;
	}
	return 0;
}