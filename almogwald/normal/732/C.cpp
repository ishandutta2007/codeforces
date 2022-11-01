#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	//int pizza[200000],n;
	long long int a, b, c, maxsimus, lost=0;
	cin >> a;
	cin >> b;
	cin >> c;
	maxsimus = max(a, max(b, c));
	lost += max( -b + maxsimus - 1, a - a);
	lost += max( -a + maxsimus - 1, a - a);
	lost += max( -c + maxsimus - 1, a - a);
	cout << lost << '\n';
	return 0;
}