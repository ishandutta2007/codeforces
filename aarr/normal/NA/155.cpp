#include <iostream>

using namespace std;

int main()
{
	int n, k, t;
	cin >> n;
	cin >> k;
	cin >> t;
	if(t > n)
	{
		cout << k - t + n;
	}
	else
	{
		cout << min(k, t);
	}
	return 0;
}