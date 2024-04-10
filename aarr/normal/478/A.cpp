#include <iostream>

using namespace std;

int main()
{
	int x, y = 0;
	for(int i = 0; i < 5; i ++)
	{
		cin >> x;
		y += x;
	}
	if(y % 5 == 0 && y > 0)
	{
		cout << y / 5;
	}
	else
	{
		cout << -1;
	}
}