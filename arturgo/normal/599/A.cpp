#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a = min(a, b + c);
	b = min(b, c + a);
	c = min(c, b + a);
	cout << a + b + c << endl;
	return 0;
}