#include <iostream>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int my_min(int a, int b)
{
	return a < b ? a : b;
}

int my_max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	int ans[1000];
	cin >> t;
	for (Loop)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)
		{
			int h = a;
			a = b;
			b = h;
		}
		if (b > c)
		{
			int h = b;
			b = c;
			c = h;
		}
		if (a > b)
		{
			int h = a;
			a = b;
			b = h;
		}
		ans[loop] = my_max(0, (c - a - 2) * 2);
	}
	for (Loop)
		cout << ans[loop] << '\n';
}