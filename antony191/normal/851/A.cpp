#include <iostream>

using namespace std;

int main()
{
	int n, k, t;
	cin >> n >> k >> t;
	int a = k;
	if (t > n) a -= t - n;
	if (t < k) a -= k - t;
	cout << a;
	return 0;
}