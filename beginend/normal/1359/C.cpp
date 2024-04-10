#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int h, c, t; scanf("%d%d%d", &h, &c, &t);
		int c1 = h + c - t * 2, c2 = h - t;
		double x = (double)-1.0 * c2 / c1;
		double mn = fabs((double)(c + h) / 2.0 - t);
		int ans = 2;
		for (int i = x - 3; i <= x + 3; i++)
			if (i >= 0 && fabs((double)((double)1.0 * (i + 1) * h + (double)i * c) / (i * 2 + 1) - t) < mn)
			{
				mn = fabs((double)((double)1.0 * (i + 1) * h + (double)i * c) / (i * 2 + 1) - t);
				ans = i * 2 + 1;
			}
		printf("%d\n", ans);
	}
	return 0;
}