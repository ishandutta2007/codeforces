#include <iostream>
using namespace std;

int my_abs(int x)
{
	return x > 0 ? x : -x;
}
int my_min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	int n[100], x[100], a[100], b[100];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n[i] >> x[i] >> a[i] >> b[i];
	}
	for (int i = 0; i < t; i++)
	{
		cout << my_min(my_abs(a[i] - b[i]) + x[i], n[i] - 1) << endl;
	}
}