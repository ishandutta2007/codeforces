#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	if (a == 1)
	{
		cout << 1 << " " << 2 << endl;
		cout << 1 << " " << 2;
	}
	else
	{
		cout << (a - 1) * 2 << " " << 2 << endl;
		cout << 1 << " " << 2;
	}
	return 0;
}