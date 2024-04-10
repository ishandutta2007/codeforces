#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int min1(int a, int b)
{
	return a <= b ? a : b;
}
int main()
{
	
	string a1;
	cin >> a1;
	int a = a1.length();
	//cout << a << endl;
	int tx = ((a - 1) / 20) + 1;
	int st = ((a - 1) / tx) + 1;
	int ast = tx * st - a;
	cout << tx << " " << st << endl;
	for (int i = 0; i < tx; i++)
	{
		cout << a1.substr(0, st - min1(min1(i, ast), 1));
		a1 = a1.substr(st - min1(min1(i, ast), 1));
		int pr = min1(min1(i, ast), 1);
		for (int j = 0; j < pr; j++)
		{
			ast--;
			cout << "*";
		}
		cout << endl;
	}
	
    return 0;
}