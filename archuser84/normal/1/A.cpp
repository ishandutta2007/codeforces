#include <iostream>
using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m >> a;
	cout << (long long)((n / a) + (n%a != 0)) * ((m / a) + (m%a != 0)) << endl;
}