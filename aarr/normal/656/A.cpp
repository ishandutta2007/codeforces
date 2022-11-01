#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long m = 1ll << n;
	if(n >= 13)
	{
		m -= 100 * (1ll << (n - 13));
	}
	cout << m;
}