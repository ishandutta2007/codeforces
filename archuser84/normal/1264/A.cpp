#include <iostream>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int main()
{
	int t, ans[10000][3] = { 0 };
	cin >> t;
	for (Loop)
	{
		int n;
		int P[400000] = { 0 };
		cin >> n;
		int size = 0;
		int lp = -1;
		for (LoopN)
		{
			int p;
			cin >> p;
			if (p != lp)
			{
				size++;
				lp = p;
			}
			P[size - 1]++;
		}
		int g = P[0], s = 0, b = 0;
		for (int i = 1; i < size; i++)
		{
			if (g + s + b + P[i] > n / 2)
				break;
			else if (s <= g)
				s += P[i];
			else
				b += P[i];
		}
		if (b <= g)
		{
			ans[loop][0] = 0;
			ans[loop][1] = 0;
			ans[loop][2] = 0;
		}
		else
		{
			ans[loop][0] = g;
			ans[loop][1] = s;
			ans[loop][2] = b;
		}
	}
	for (Loop)
	{
		printf("%i %i %i\n", ans[loop][0], ans[loop][1], ans[loop][2]);
	}
}