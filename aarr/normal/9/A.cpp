#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	if(max(a, b) == 6)
	{
		cout << 1 << "/" << 6;
	}
	if(max(a, b) == 5)
	{
		cout << 1 << "/" << 3;
	}
	if(max(a, b) == 4)
	{
		cout << 1 << "/" << 2;
	}
	if(max(a, b) == 3)
	{
		cout << 2 << "/" << 3;
	}
	if(max(a, b) == 2)
	{
		cout << 5 << "/" << 6;
	}
	if(max(a, b) == 1)
	{
		cout << 1 << "/" << 1;
	}
	return 0;
}