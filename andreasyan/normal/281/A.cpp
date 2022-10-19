#include <iostream>
using namespace std;

char a[1003];
int main()
{
	int  n;
	char e;
	cin >> a;
	if (a[0] >= 'a' && a[0] <= 'z')
	{
		e = a[0] - 'a' + 'A';
		a[0] = e;
	}
	cout << a << endl;
	return 0;
}