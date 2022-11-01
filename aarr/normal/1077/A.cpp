#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		long long a, b, k;
		cin >> a;
		cin >> b;
		cin >> k;
		cout << a * (k - k / 2) - (b * (k / 2)) << endl;
	}
	return 0;
}