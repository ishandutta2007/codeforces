#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n, h, w, x, y, a, b, j;
bool pat[500001];
char in;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		if (in == '+')
		{
			cin >> x >> y;
			if (min(x, y) > a)
			{
				a = min(x, y);
			}
			if (max(x, y) > b)
				b = max(x, y);
		}
		else
		{
			cin >> h >> w;
			if (min(h, w) >= a && max(h, w) >= b)
			{
				pat[j] = 1;
			}
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (pat[i])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}