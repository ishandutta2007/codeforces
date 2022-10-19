#include <iostream>
#define Loop int i = 0; i < t; i++
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
	int x[10000], y[10000];
	bool ans[10000] = { 0 };
	cin >> t;
	for (Loop)
	{
		cin >> x[i] >> y[i];
		if (x[i] >= 4 || (x[i] + !(x[i] % 2)) >= y[i])
		{
			ans[i] = true;
		}
	}
	for (Loop)
	{
		cout << (ans[i] ? "YES" : "NO") << endl;
	}
}