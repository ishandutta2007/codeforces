#include <iostream>

using namespace std;

int a[2005];
int main()
{
	int n, d, b = 0;
	cin >> n;
	cin >> d;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i < n; i ++)
	{
		if(a[i] <= a[i - 1])
		{
			int c = (a[i - 1] - a[i]) / d + 1;
			b += c;
			a[i] += c * d;
		}
	}
	cout << b;
	return 0;
}