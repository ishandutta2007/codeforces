#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	cout << max(abs(a[0] - b[0]),abs(a[1] - b[1])) << endl;
	while(a[0] > b[0] && a[1] > b[1])
	{
		a[0] -= 1;
		a[1] -= 1;
		cout << "LD" << endl;
	}
	while(a[0] > b[0] && a[1] < b[1])
	{
		a[0] -= 1;
		a[1] += 1;
		cout << "LU" << endl;
	}
	while(a[0] < b[0] && a[1] > b[1])
	{
		a[0] += 1;
		a[1] -= 1;
		cout << "RD" << endl;
	}
	while(a[0] < b[0] && a[1] < b[1])
	{
		a[0] += 1;
		a[1] += 1;
		cout << "RU" << endl;
	}
	while(a[0] > b[0])
	{
		cout << "L" << endl;
		a[0] -= 1;
	}
	while(a[0] < b[0])
	{
		cout << "R" << endl;
		a[0] += 1;
	}
	while(a[1] > b[1])
	{
		cout << "D" << endl;
		a[1] -= 1;
	}
	while(a[1] < b[1])
	{
		cout << "U" << endl;
		a[1] += 1;
	}
	return 0;
}