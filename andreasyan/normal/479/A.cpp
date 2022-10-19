#include <iostream>
using namespace std;

int main()
{
	int a, b, c,maxim=0;
	cin >> a >> b >> c;
	if (a + b + c > maxim)
		maxim = a + b + c;
	if (a * b * c > maxim)
		maxim = a * b * c;
	if (a + b * c > maxim)
		maxim = a + b * c;
	if (a * b + c > maxim)
		maxim = a * b + c;
	if ((a + b) + c > maxim)
		maxim = (a + b) + c;
	if ((a * b) * c > maxim)
		maxim = (a * b) * c;
	if ((a + b) * c > maxim)
		maxim = (a + b) * c;
	if ((a * b) + c > maxim)
		maxim = (a * b) + c;
	if (a + (b + c) > maxim)
		maxim = a + (b + c);
	if (a * (b * c) > maxim)
		maxim = a * (b * c);
	if (a + (b * c) > maxim)
		maxim = a + (b * c);
	if (a * (b + c) > maxim)
		maxim = a * (b + c);
	cout << maxim << endl;
	return 0;
}