#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (k == n) cout << 0 << " " << 0;
	else if (k == 0) cout << 0 << " " << 0;
	else if (2 * k > n) cout << 1 << " " << n - k;
	else if (3 * k >= n) cout << 1 << " " << n - k;
	else cout << 1 << " " << 2 * k;
	return 0;
}