#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;


int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int a, b;
		cin >> a >> b;
		int x = abs(a - b);
		int h = 0;
		int c = 0;
		while (h != x)
		{
			while (h < x)
			{
				++c;
				h += c;
			}
			if (h != x)
			{
				x += 2;
			}
		}
		cout << c << '\n';
	}
}