#include <iostream>
using namespace std;
 
struct ban
{
	int q;
	int pos;
};
int n, m, k = 1, res, l;
int c[300002];
ban b[300002];
 
int main()
{
	int i, j;
	int x, y;
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> x >> y;
		if (x == 1)
		{
			res++;
			b[y].q++;
			l++;
			c[l] = y;
			cout << res << endl;
			continue;
		}
		if (x == 2)
		{
			b[y].pos = l + 1;
			res -= b[y].q;
			b[y].q = 0;
		}
		if (x == 3)
		{
			for (j = k; j <= y; j++)
			{
				if (c[j] && b[c[j]].q && j >= b[c[j]].pos)
				{
					b[c[j]].q--;
					c[j] = 0;
					res--;
				}
			}
			if (y + 1 > k)
				k = y + 1;
		}
		cout << res << endl;
	}
//	system("pause");
	return 0;
}