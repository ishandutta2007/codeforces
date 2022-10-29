#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long a, b, k;
	cin >> a >> b;
	k = trunc(sqrt(a));
	if (k*(k+1) > b) cout << "Valera";
	else cout << "Vladik";
	return 0;
}