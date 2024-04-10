#include <iostream>
using namespace std;

int n, m, k,x[4003],y[4003];
int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n + 1; i++)
		cin >> x[i] >> y[i];
	x[n+2]=x[1];
	y[n+2]=y[1];
	for (i = 0; i < n-1; i++)
	{
		if (x[i] < x[i + 1] && y[i + 1] < y[i + 2])
			m++;
		if (x[i] > x[i + 1] && y[i + 1] > y[i + 2])
			m++;
		if (y[i] > y[i + 1] && x[i + 1] < x[i + 2])
			m++;
		if (y[i] < y[i + 1] && x[i + 1] > x[i + 2])
			m++;
	}
	cout << m << endl;
	return 0;
}