#include <iostream>
using namespace std;

int main()
{
	long long a, b, c,x,y;
	cin >> a >> b >> c;
	if (a%c != 0)
		x = a / c + 1;
	else
		x = a / c;
	if (b%c != 0)
		y = b / c + 1;
	else
		y = b / c;
	cout << x*y << endl;
	return 0;
}