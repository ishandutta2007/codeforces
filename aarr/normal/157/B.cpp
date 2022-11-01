#include <iostream>

#include <algorithm>

using namespace std;

int a[105];
const double pi = 3.1415926536;
int main()
{
	int n, s = 0;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	sort(a, a + n + 1);
	for(int i = n - 1; i >= 0; i-= 2)
	{
		s += a[i + 1] * a[i + 1] - a[i] * a[i];
	}
	cout << pi * s;
	return 0;
}