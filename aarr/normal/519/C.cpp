#include <iostream>

using namespace std;

int main()
{
	int n, m, a;
	cin >> n;
	cin >> m;
	a = min (n, m);
	cout << min(a, (m + n) / 3);
	return 0;
}