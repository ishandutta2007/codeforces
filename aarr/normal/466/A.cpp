#include <iostream>

using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n;
	cin >> m;
	cin >> a;
	cin >> b;
	cout << min(min(n * a, (n / m) * b + (n % m) * a), (n / m + 1) * b);
}