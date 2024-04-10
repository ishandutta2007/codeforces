#include <bits/stdc++.h>
using namespace std;
typedef double ld;
ld dis(ld x, ld y, ld x2, ld y2)
{
	return sqrt(pow((x-x2), 2.0) + pow((y-y2), 2.0));
}
int x[1010];
int r;
ld Y[1010];
int n;
int main()
{
	scanf("%d %d", &n, &r);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i++)
	{
		ld y = r;
		for (int j = 0; j < i; j++)
		{
			if (abs(x[i]-x[j]) > 2*r) continue;
		//	printf("%d %d\n", i, j);
			ld s = Y[j];
			ld e = 9999999999999999999999999999999.9;
			while (e-s > 1e-10)
			{
				ld m = (s+e)/2;
				if (dis(x[i], m, x[j], Y[j]) <= 2*r) s = m;
				else e = m;
			}
			y = max(y, s);
		}
		printf("%.15lf ", y);
		Y[i] = y;
	}
}