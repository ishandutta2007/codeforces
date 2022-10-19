#include <iostream>
using namespace std;

int my_max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int t;
	int x[1000][3];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x[i][0] >> x[i][1] >> x[i][2];
		if (x[i][0] > x[i][1])
		{
			int h = x[i][0];
			x[i][0] = x[i][1];
			x[i][1] = h;
		}
		if (x[i][1] > x[i][2])
		{
			int h = x[i][1];
			x[i][1] = x[i][2];
			x[i][2] = h;
		}
		if (x[i][0] > x[i][1])
		{
			int h = x[i][0];
			x[i][0] = x[i][1];
			x[i][1] = h;
		}
	}

	for (int i = 0; i < t; i++)
	{
		int h = my_max((x[i][0] - (x[i][2] - x[i][1])), 0);
		cout << x[i][0] + x[i][1] - h/2 - h%2 << endl;
	}
}