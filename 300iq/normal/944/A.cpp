#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int rec(int l, int r, int id)
{
	if (r - l == 1)
	{
		return (l == a || l == b);
	}
	else
	{
		int m = (l + r) / 2;
		int x = rec(l, m, id - 1);
		int y = rec(m, r, id - 1);
		if (x + y == 2)
		{
			if (l == 0 && r == n)
			{
				cout << "Final!" << '\n';
			}
			else
			{
				cout << id << '\n';
			}
			exit(0);
		}
		else
		{
			return x + y;
		}
	}
}

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	a--, b--;
	int lg = 0;
	int x = n;
	while (x % 2 == 0) lg++, x /= 2;
	rec(0, n, lg);
}