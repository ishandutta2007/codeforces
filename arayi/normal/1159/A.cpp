#include <iostream>
using namespace std;

int main()
{
	int n, minus, plus, tiv;
	string a;
	cin >> n >> a;
	plus = 0;
	minus = 0;
	tiv = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '+')
		{
			k++;
		}
		else if ((a[i] == '-') && (k == 0))
			tiv++;
		else if (a[i] == '-')
			k--;
	}
	for (int j = 0; j < n; j++)
	{
		if (a[j] == '+')
			tiv++;
		else if (a[j] == '-')
			tiv--;
	}
	cout << tiv;

}