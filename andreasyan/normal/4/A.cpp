#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0 && n != 2)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}